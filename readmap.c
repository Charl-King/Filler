/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:46:00 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 18:01:06 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
