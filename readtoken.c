/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:50:17 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 18:01:25 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		clear_token(t_piece *token)
{
	int i;

	i = 0;
	while (i < token->y)
		ft_strdel((&token->data[i++]));
	ft_memdel((void **)token->data);
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
