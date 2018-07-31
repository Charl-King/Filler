/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 09:53:48 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 18:19:55 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef	struct	s_player
{
	char me;
	char enemy;
}				t_player;

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_board
{
	int			x;
	int			y;
	char		**data;
	t_player	player;
}				t_board;

typedef struct	s_piece
{
	int		x;
	int		y;
	char	**data;
	t_coord	offset;
	t_coord	trim;
}				t_piece;

typedef struct	s_a
{
	t_player	player;
	t_board		board;
	t_piece		piece;
	t_coord		opt;
	t_coord		*targets;
	int			i;
	int			counter;
}				t_a;

void			set_board_size(t_board *map, char *str);
t_player		init(void);
t_board			init_board(t_player *player);
void			update_board(t_board *board);
void			clear_token(t_piece *token);
t_piece			get_piece(void);
void			trim(t_piece *piece);
void			place(t_coord *coord);
int				check_placement(t_board *brd, t_piece *piece, t_coord *crd);
int				distance(t_coord *a, t_coord *b);
t_coord			get_placement(t_board *map, t_piece *token, t_coord *target);

#endif
