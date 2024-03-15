/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:05:00 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 20:18:11 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char *)s1 + x) == 
		*((unsigned char *)s2 + x) && n - 1 > x)
	{
		x++;
	}
	return (*((unsigned char *)s1 + x) - *((unsigned char *)s2 + x));
}
