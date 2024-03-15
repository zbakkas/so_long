/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:57:11 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/24 15:27:44 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	t;

	s = 0;
	d = 0;
	t = 0;
	while (src[s])
		s++;
	while (dst[d])
		d++;
	if (d < dstsize)
		t = s + d;
	else
		return (s + dstsize);
	s = 0;
	while (((dstsize - 1) - d) > 0 && src[s])
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (t);
}
