/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:50:31 by cking             #+#    #+#             */
/*   Updated: 2018/06/06 13:11:05 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srcc;
	unsigned char	*dstc;

	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	if (srcc < dstc)
	{
		while (len--)
			dstc[len] = srcc[len];
	}
	else
	{
		ft_memcpy(dstc, srcc, len);
	}
	return (dst);
}
