/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnum_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:47:14 by cking             #+#    #+#             */
/*   Updated: 2018/07/10 14:47:22 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnum_n(char *str, int n)
{
	int i = 0;
	int out = 0;
	int counter = 0;
	int start = 0;
	int end = 0;

	while (counter < n)
	{
		if (ft_isspace(str[i]) && ft_isdigit(str[i + 1]))
		{
			start = i + 1;
			counter++;
		}
		if (i == 0 && ft_isdigit(str[i]))
		{
			start = i;
			counter++;
		}
		i++;
	}
	counter = 0;
	i = 0;
	while (counter < n)
	{
		if (ft_isdigit(str[i]) && (ft_isspace(str[i + 1]) || str[i + 1] == '\0'))
		{
			end = i;
			counter++;
		}
		i++;
	}
	out = ft_atoi(ft_strsub(str,start,(end - start + 1)));
	return (out);
}
