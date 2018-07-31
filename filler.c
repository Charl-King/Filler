/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 08:11:01 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 18:16:58 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"
#include <stdio.h>

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

void	norm(t_a a)
{
	if (a.opt.x != -999)
		place(&a.opt);
	else
		exit(1);
	if (a.counter++ >= a.board.y + 20)
	{
		a.counter = 0;
		a.i++;
	}
	if (a.i == 8)
		a.i = 1;
}

int		main(void)
{
	t_a			a;

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
		norm(a);
	}
}
