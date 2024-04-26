/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:24 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/24 17:14:31 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wind_size_x(char **str)
{
	int	x;

	x = 0;
	while (str[0][x])
		x++;
	return (x * 64);
}

int	wind_size_y(char **str)
{
	int	y;

	y = 0;
	while (str[y])
		y++;
	return (y * 64);
}