/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:03:07 by cking             #+#    #+#             */
/*   Updated: 2018/07/31 10:05:29 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		main(int argc, char **argv)
{
	char *str = argv[1];
	ft_putnbr(ft_getnum_n(str, 2));
}
