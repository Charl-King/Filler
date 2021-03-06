/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:44:26 by cking             #+#    #+#             */
/*   Updated: 2018/06/04 10:09:42 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcchr(const char *s, int c)
{
	char	x;
	int		i;
	char	*y;

	i = 0;
	y = (NULL);
	x = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == x)
		{
			*y = s[i];
		}
		i++;
	}
	if (x == '\0')
		*y = s[i + 1];
	return (y);
}
