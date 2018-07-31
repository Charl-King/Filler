/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:15:15 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 18:20:32 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		place(t_coord *coord)
{
	ft_putnbr(coord->y);
	ft_putchar(' ');
	ft_putnbr(coord->x);
	ft_putchar('\n');
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
