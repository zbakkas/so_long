/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:45:20 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/28 18:17:43 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	lenn(char *s1)
{
	int	x;

	x = 0;
	while (s1[x])
	{
		x++;
	}
	return (x);
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	int		x;

	x = 0;
	re = malloc(sizeof(char) * lenn((char *)s1) + 1);
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[x] = s1[x];
		x++;
	}
	re[x] = '\0';
	return (re);
}
