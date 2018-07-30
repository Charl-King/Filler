/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:46:49 by cking             #+#    #+#             */
/*   Updated: 2018/07/30 14:35:40 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"
#include <stdio.h>

void		error(int x)
{
	ft_putstr_fd("Error", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd('\n', 2);
}

void	put_coord(t_coord *coord)
{
	ft_putstr_fd("(", 2);
	ft_putnbr_fd(coord->y, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(coord->x, 2);
	ft_putstr_fd(")\n", 2);
}

void    place (t_coord *coord)
{
    ft_putnbr(coord->y);
	ft_putchar(' ');
	ft_putnbr(coord->x);
	ft_putchar('\n');
}

void	print_map(t_board *map)
{
	int i;

	i = 0;
	while (i < map->y)
		ft_putendl_fd(map->data[i++], 2);
}

void	print_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->y)
		ft_putendl_fd(piece->data[i++], 2);
}

void	clear_token(t_piece *token)
{
	int i;

	i = 0;
	while (i < token->y)
		ft_strdel((&token->data[i++]));
	ft_memdel((void **)token->data);
}

void	set_board_size(t_board *map, char *str)
{
	map->y = ft_getnum_n(str, 1);
	map->x = ft_getnum_n(str, 2);
}

t_player	init(void)
{
	char **line;
	int player_num;
	t_player player;

	line = malloc(1000);
	*line = malloc(1000);
	get_next_line(0, line);
	char *str = ft_strchr(*line, 'p');
	str++;
	player_num = ft_atoi(str);
	if (player_num == 1)
	{
		player.me = 'O';
		player.enemy = 'X';
	}
	if (player_num == 2)
	{
		player.me = 'X';
		player.enemy = 'O';
	}
	ft_memdel((void *)line);
	ft_memdel((void *)*line);
	return (player);
}

t_board	init_board(t_player *player)
{
	t_board map;
	char **line;
	map.player = *player;

	line = malloc(1000);
	*line = malloc(1000);
	
	get_next_line(0, line);
	set_board_size(&map, *line);
	ft_memdel((void *)line);
	ft_memdel((void *)*line);
	map.data = (char **)malloc(sizeof(char *) * map.y);
	return (map);
}

void	update_board(t_board *board)
{
	int i;
	char **line;
	char *temp;

	line = malloc(1000);
	*line = malloc(1000);
	i = 0;

	get_next_line(0, line);
	if (ft_strncmp(*line,"Plateau", 6) == 0)
		get_next_line(0, line);
	
	while (i < board->y)
	{
		get_next_line(0, line);
		temp = ft_strchr(*line, ' ');
		temp++;
		board->data[i] = ft_strdup(temp);
		i++;
	}
	ft_memdel((void *)line);
	ft_memdel((void *)*line);
}

t_piece	get_piece()
{
	int i;
	char **line;
	t_piece piece;
	
	i = 0;
	line = malloc(1000);
	*line = malloc(1000);
	get_next_line(0, line);
	piece.y = ft_getnum_n(*line, 1);
	piece.x = ft_getnum_n(*line, 2);
	piece.data = (char **)malloc(sizeof(char *) * piece.y);
	while (i < piece.y)
	{
		get_next_line(0, line);
		piece.data[i] = ft_strdup(*line);
		i++;
	}
	ft_memdel((void *)line);
	ft_memdel((void *)*line);
	return (piece);
}

int		check_placement(t_board *board, t_piece *piece, t_coord *coord)
{
	int i;
	int j;
	int overlap;

	i = 0;
	j = 0;
	overlap = 0;

	if ((piece->trim.y - piece->offset.y + coord->y) >= board->y)
		return (0);
	if ((piece->trim.x - piece->offset.x + coord->x) >= board->x)
		return (0);
	while (i <= (piece->trim.y - piece->offset.y))
	{
		while (j <= (piece->trim.x - piece->offset.x))
		{
			if ((piece->data[piece->offset.y + i][piece->offset.x + j]) == '*')
			{
				if (board->data[coord->y + i][coord->x + j] == board->player.me)
					overlap++;
				if (board->data[coord->y + i][coord->x + j] == board->player.enemy)
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (overlap == 1 ? 1 : 0);
}

void	trim(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	piece->offset.x = piece->x;
	piece->offset.y = piece->y;
	piece->trim.x = 0;
	piece->trim.y = 0;

	while (i < piece->y)
	{
		while (j < piece->x)
		{
			if (piece->data[i][j] == '*')
			{
				if (i < piece->offset.y)
					piece->offset.y = i;
				if (i > piece->trim.y)
					piece->trim.y = i;
				if (j < piece->offset.x)
					piece->offset.x = j;
				if (j > piece->trim.x)
					piece->trim.x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		distance(t_coord *a, t_coord *b)
{
	int x;
	int y;

	x = a->x - b->x;
	y = a->y - b->y;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	return (x + y);
}

//t_coord get_placement(t_board map, t_piece token, t_coord target)
//{
//	
//}

int		main(void)
{
	t_player player = init();
	t_board board = init_board(&player);
	t_piece piece;
	t_coord coord;
	t_coord opt;
	t_coord target[6];
	int inc = 0;

	while (1)
	{
		int i = 0;
		int j = 0;
		coord.x = 0;
		coord.y = 0;
		opt.x = 0;
		opt.y = 0;
		int mindis = board.x + board.y;
		int found = 0;

		update_board(&board);
		target[0].y = board.y/3;
		target[0].x = 2;
		target[1].y = board.y/3;
		target[1].x = board.x-2;
		target[2].y = 2;
		target[2].x = 2;
		target[3].y = board.y-2;
		target[3].x = board.x-2;
		target[4].y = board.y-2;
		target[4].x = 2;
		target[5].y = 2;
		target[5].x = board.x - 2;
		target[6].y = board.y - 2;
		target[6].x = 2;
		piece = get_piece();
		trim(&piece);
		while (i < board.y)
		{
			while (j < board.x)
			{
				coord.y = i;
				coord.x = j;
				if (check_placement(&board, &piece, &coord) && distance(&coord,&target[inc]) < mindis)
				{
					opt.y = i - piece.offset.y;
					opt.x = j - piece.offset.x;
					mindis = distance(&coord, &target[inc]);
					found = 1;
				}
				j++;
			}
			j = 0;
			i++;
		}
		if (mindis < 5 && inc < 6)
			inc++;
		mindis = 0;
		clear_token(&piece);
		if (found)
			place(&opt);
		else
		{
			write(1, "1 1", 3);
			exit(1);
		}	
	}
	return (0);
}
