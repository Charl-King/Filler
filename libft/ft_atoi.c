/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:58:37 by cking             #+#    #+#             */
/*   Updated: 2018/06/06 10:59:27 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	out;
	int	sign;
	int i;

	sign = 1;
	out = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] != '+')
			return (0);
		str++;
	}
	while (ft_isdigit(str[i]))
	{
		out = out * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (out);
}
