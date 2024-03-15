/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:38:54 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 16:05:04 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == (unsigned char)c)
		{
			return ((char *)(str + x));
		}
		x++;
	}
	if (str[x] == (unsigned char)c)
	{
		return ((char *)(str + x));
	}
	return (NULL);
}
