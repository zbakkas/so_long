/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:24 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/01 12:20:33 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	draw_score(void *mlx, void *win, int move)
{
	char	*str;

	str = ft_itoa(move);
	mlx_string_put(mlx, win, 1, 1, 0x000000, "move:");
	mlx_string_put(mlx, win, 64, 1, 0x000000, str);
	free(str);
}
