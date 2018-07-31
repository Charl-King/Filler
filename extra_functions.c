/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:19:16 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 15:22:29 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

