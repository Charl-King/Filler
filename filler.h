/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 09:53:48 by cking             #+#    #+#             */
/*   Updated: 2018/07/30 14:28:23 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

typedef	struct s_player
{
	char me;
	char enemy;
}	t_player;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef struct s_board
{
	int x;
	int y;
	char **data;
	t_player player;
} t_board;

typedef struct s_piece
{
	int x;
	int y;
	char **data;
	t_coord offset;
	t_coord trim;
} t_piece;
