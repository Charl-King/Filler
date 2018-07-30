/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:10:41 by cking             #+#    #+#             */
/*   Updated: 2018/06/07 09:25:54 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*out;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i++] != '\0')
		out[i - 1] = s1[i - 1];
	while (s2[j++] != '\0')
		out[(i - 1) + (j - 1)] = s2[(j - 1)];
	out[(i - 1) + (j - 1)] = '\0';
	return (out);
}
