/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:44:15 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/23 20:03:06 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	longgg(unsigned long long int re, int sin, const char *str, int x)
{
	while (str[x] >= 48 && str[x] <= 57)
	{
		re *= 10;
		re += str[x] - 48;
		if (re > 9223372036854775807 && sin == -1)
			return (0);
		if (re > 9223372036854775807 && sin == 1)
			return (-1);
		x++;
	}
	return (re * sin);
}

int	ft_atoi(const char *str)
{
	int						x;
	unsigned long long int	re;
	int						sin;

	x = 0;
	re = 0;
	sin = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-')
	{
		sin *= -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	return (longgg(re, sin, str, x));
}
