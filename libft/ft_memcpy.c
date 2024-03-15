/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:27:52 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 16:32:11 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	x;
	int	s;

	x = 0;
	s = n;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	x = 0;
	while (n > 0)
	{
		*((char *)dest + x) = *((char *)src + x);
		n--;
		x++;
	}
	return (dest);
}
