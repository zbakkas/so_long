/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:27:33 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/30 21:37:40 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	chick_l(int n)
{
	int	x;

	x = 0;
	if (n <= 9 && n >= 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		x++; 
	}
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*re;
	int		x;
	int		j;

	j = n;
	x = chick_l(n) -1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	re = ft_calloc(chick_l(n) + 1, sizeof(char));
	if (!re)
		return (NULL);
	if (n < 0)
		j *= -1;
	while (j != 0)
	{
		re[x--] = (j % 10) + '0';
		j = j / 10;
	}
	if (n < 0)
		re[x] = '-';
	return (re);
}
