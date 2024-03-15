/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:04:01 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 21:20:24 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	x;

	x = 0;
	while (len)
	{
		*((unsigned char *)(b + x)) = (unsigned char)c;
		len--;
		x++;
	}
	return (b);
}
