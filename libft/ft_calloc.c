/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:40:56 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/24 22:03:38 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{/*
	char	*re;
	size_t	t;

	t = count * size;
	if (t != 0)
		if (t / size != count)
			return (NULL);
	re = malloc (count * size);
	if (!re)
		return (NULL);
	ft_bzero(re, size * count);
	return (re);*/
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}
