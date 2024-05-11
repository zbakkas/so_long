/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:44 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/07 19:59:05 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strnstr(char *str)
{
	int	x;

	x = ft_strlen(str) - 1;
	if (str[x--] != 'r')
		return (1);
	if (str[x--] != 'e')
		return (1);
	if (str[x--] != 'b')
		return (1);
	if (str[x--] != '.')
		return (1);
	return (0);
}
