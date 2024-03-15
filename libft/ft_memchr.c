/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:44:26 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 20:15:48 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const void	*re;
	size_t		x;

	x = 0;
	re = str;
	while (n > x)
	{
		if (*((unsigned char *)re + x) == (unsigned char)c)
		{
			return ((void *)re + x);
		}
		x++;
	}
	return (NULL);
}
