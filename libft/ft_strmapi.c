/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:04:58 by cking             #+#    #+#             */
/*   Updated: 2018/06/04 08:05:05 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		index;

	if (!s || !f)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		ptr[index] = f(index, s[index]);
		++index;
	}
	ptr[index] = '\0';
	return (ptr);
}
