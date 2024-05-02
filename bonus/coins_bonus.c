/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:34:42 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/29 10:51:04 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**coins_an(void *mlx)
{
	int		width;
	int		height;
	void	**c;

	c = (void **)malloc(6 * sizeof(void *));
	c[0] = mlx_xpm_file_to_image(mlx, "./image/coin_1.xpm", &width, &height);
	if (!c[0])
		return (free(c), NULL);
	c[1] = mlx_xpm_file_to_image(mlx, "./image/coin_2.xpm", &width, &height);
	if (!c[1])
		return (free(c), NULL);
	c[2] = mlx_xpm_file_to_image(mlx, "./image/coin_3.xpm", &width, &height);
	if (!c[2])
		return (free(c), NULL);
	c[3] = mlx_xpm_file_to_image(mlx, "./image/coin_4.xpm", &width, &height);
	if (!c[3])
		return (free(c), NULL);
	c[4] = mlx_xpm_file_to_image(mlx, "./image/coin_5.xpm", &width, &height);
	if (!c[4])
		return (free(c), NULL);
	c[5] = mlx_xpm_file_to_image(mlx, "./image/coin_6.xpm", &width, &height);
	if (!c[5])
		return (free(c), NULL);
	return (c);
}

int	get_conis_in_map(char **str)
{
	int	x;
	int	y;
	int	re;

	x = 0;
	re = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == 'C')
				re++;
			y++;
		}
		x++;
	}
	return (re);
}

void	get_coins(char **str, int *p_p, int *coins)
{
	if (str[p_p[3]][p_p[2]] == 'C')
	{
		str[p_p[3]][p_p[2]] = '0';
		(*coins)--;
	}
}

void	p_coins(t_map map)
{
	int	x;
	int	y;
	int	m_x;
	int	m_y;

	y = 0;
	m_y = 0;
	while (map.str[m_y])
	{
		m_x = 0;
		x = 0;
		while (map.str[m_y][m_x])
		{
			if (map.str[m_y][m_x] == 'C')
				mlx_put_image_to_window(map.mlx, map.win,
					map.coins[map.frem_coins], x, y); 
			x += 64;
			m_x++;
		}
		m_y++;
		y += 64;
	}
}
