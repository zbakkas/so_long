/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:22:06 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 16:39:49 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	int		r;

	x = 0;
	r = 0;
	while (src[r])
	{
		r++;
	}
	if (dstsize == 0)
	{
		return (r);
	}
	while (src[x] && dstsize - 1 > x)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (r);
}
