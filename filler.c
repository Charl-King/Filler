/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 08:11:01 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 17:03:28 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"
#include <stdio.h>

void		place(t_coord *coord)
{
	ft_putnbr(coord->y);
	ft_putchar(' ');
	ft_putnbr(coord->x);
	ft_putchar('\n');
}

void		clear_token(t_piece *token)
{
	int i;

	i = 0;
	while (i < token->y)
		ft_strdel((&token->data[i++]));
	ft_memdel((void **)token->data);
}

void		set_board_size(t_board *map, char *str)
{
	map->y = ft_getnum_n(str, 1);
	map->x = ft_getnum_n(str, 2);
}

t_player	init(void)
{
	char		**line;
	int			player_num;
	char		*str;
	t_player	player;

	line = malloc(1000);
	*line = malloc(1000);
	get_next_line(0, line);
	str = ft_strchr(*line, 'p');
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

t_board		init_board(t_player *player)
{
	t_board		map;
	char		**line;

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

void		update_board(t_board *board)
{
	int		i;
	char	**line;
	char	*temp;

	line = malloc(1000);
	*line = malloc(1000);
	i = 0;
	get_next_line(0, line);
	if (ft_strncmp(*line, "Plateau", 6) == 0)
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

t_piece		get_piece(void)
{
	int		i;
	char	**line;
	char	*str;
	t_piece	piece;

	i = 0;
	line = malloc(1000);
	*line = malloc(1000);
	get_next_line(0, line);
	str = (ft_strchr(*line, ' ') + 1);
	piece.y = ft_atoi(str);
	piece.x = ft_atoi(ft_strchr(str, ' ') + 1);
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

int			check_placement(t_board *brd, t_piece *piece, t_coord *crd)
{
	int i;
	int j;
	int ovl;

	i = 0;
	ovl = 0;
	if (((piece->trim.y - piece->offset.y + crd->y) >= brd->y)
		|| ((piece->trim.x - piece->offset.x + crd->x) >= brd->x))
		return (0);
	while (i <= (piece->trim.y - piece->offset.y))
	{
		j = 0;
		while (j <= (piece->trim.x - piece->offset.x))
		{
			if ((piece->data[piece->offset.y + i][piece->offset.x + j]) == '*')
			{
				(brd->data[crd->y + i][crd->x + j] == brd->player.me) && ovl++;
				if (brd->data[crd->y + i][crd->x + j] == brd->player.enemy)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (ovl == 1 ? 1 : 0);
}

void		trim(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	piece->offset.x = piece->x;
	piece->offset.y = piece->y;
	piece->trim.x = 0;
	piece->trim.y = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{
			if (piece->data[i][j] == '*')
			{
				(i < piece->offset.y) && (piece->offset.y = i);
				(i > piece->trim.y) && (piece->trim.y = i);
				(j < piece->offset.x) && (piece->offset.x = j);
				(j > piece->trim.x) && (piece->trim.x = j);
			}
			j++;
		}
		i++;
	}
}

int			distance(t_coord *a, t_coord *b)
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

t_coord		get_placement(t_board *map, t_piece *token, t_coord *target)
{
	t_coord	coord;
	int		dist;
	t_coord	out;

	coord.y = -1;
	dist = map->y + map->x;
	out.x = -999;
	while (coord.y++ < map->y)
	{
		coord.x = -1;
		while (coord.x++ < map->x)
		{
			if (check_placement(map, token, &coord))
			{
				if (distance(&coord, target) < dist)
				{
					dist = distance(&coord, target);
					out.y = coord.y - token->offset.y;
					out.x = coord.x - token->offset.x;
				}
			}
		}
	}
	return (out);
}

void	set_targets(t_board *board, t_coord *targets)
{
	targets[0].y = -5;
	targets[0].x = board->x / 5;
	targets[1].y = board->y / 2;
	targets[1].x = board->x / 2;
	targets[2].y = board->y;
	targets[2].x = board->x;
	targets[3].y = board->y / 3;
	targets[3].x = 5;
	targets[4].y = board->y;
	targets[4].x = -10;
	targets[5].y = board->y / 3;
	targets[5].x = board->x;
	targets[6].y = 5;
	targets[6].x = board->x / 3 * 2;
	targets[7].y = board->y / 2;
	targets[7].x = board->x / 2;
}

int		main(void)
{
	s_a			a;

	a.i = 0;
	a.counter = 0;
	a.player = init();
	a.board = init_board(&a.player);
	a.targets = (t_coord *)malloc(sizeof(t_coord) * 8);
	set_targets(&a.board, a.targets);
	while (1)
	{
		update_board(&a.board);
		a.piece = get_piece();
		trim(&a.piece);
		a.opt = (get_placement(&a.board, &a.piece, &a.targets[a.i]));
		clear_token(&a.piece);
		if (a.opt.x != -999)
			place(&a.opt);
		else
		{
			write(1, "0 0", 3);
			exit(1);
		}
		if (a.counter++ >= a.board.y + 20)
		{
			a.counter = 0;
			a.i++;
		}
		if (a.i == 8)
			a.i = 1;
	}
}
