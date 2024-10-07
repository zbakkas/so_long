/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:58:00 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/28 19:25:19 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_ob_p(t_map map, int m_y, int y)
{
	int	x;
	int	m_x;

	m_x = 0;
	x = 0;
	while (map.str[m_y][m_x])
	{
		if (map.str[m_y][m_x] == '1' && m_y == 0 && !map.str[m_y][m_x + 1])
			mlx_put_image_to_window(map.mlx, map.win, map.wall_r_up, x, y); 
		else if (map.str[m_y][m_x] == '1' && m_y == 0 && m_x == 0)
			mlx_put_image_to_window(map.mlx, map.win, map.wall_l_up, x, y); 
		else if (map.str[m_y][m_x] == '1' && m_y == 0)
			mlx_put_image_to_window(map.mlx, map.win, map.wall, x, y); 
		else if (map.str[m_y][m_x] == '1' && 
		m_x == 0 && m_y != 0 && map.str[m_y + 1])
			mlx_put_image_to_window(map.mlx, map.win, map.wall_l, x, y); 
		else if (map.str[m_y][m_x] == '1' && !map.str[m_y + 1])
			mlx_put_image_to_window(map.mlx, map.win, map.wall_down, x, y); 
		else if (map.str[m_y][m_x] == '1' && !map.str[m_y][m_x + 1])
			mlx_put_image_to_window(map.mlx, map.win, map.wall_r, x, y); 
		else if (map.str[m_y][m_x] == '1')
			mlx_put_image_to_window(map.mlx, map.win, map.wall_o, x, y); 
		x += 64;
		m_x++;
	}
}

void	p_ob(t_map map)
{
	int	y;
	int	m_y ;

	y = 0;
	m_y = 0;
	while (map.str[m_y])
	{
		p_ob_p(map, m_y, y);
		m_y++;
		y += 64; 
	}
}

void	p_bk(t_map map)
{
	int	y;
	int	m_y ;
	int	x;
	int	m_x;

	y = 0;
	m_y = 0;
	while (map.str[m_y])
	{
		m_x = 0;
		x = 0;
		while (map.str[m_y][m_x])
		{
			mlx_put_image_to_window(map.mlx, map.win, map.bk, x, y);
			x += 64;
			m_x++;
		}
		m_y++;
		y += 64; 
	}
}

void	p_door(void *mlx, void *win, t_map map, char **maap)
{
	int	x;
	int	y;
	int	m_x;
	int	m_y;

	y = 0;
	m_y = 0;
	while (maap[m_y])
	{
		m_x = 0;
		x = 0;
		while (maap[m_y][m_x])
		{
			if (maap[m_y][m_x] == 'E' && map.coins_cou <= 0)
				mlx_put_image_to_window(mlx, win, map.door_open, x, y); 
			else if (maap[m_y][m_x] == 'E')
				mlx_put_image_to_window(mlx, win, map.door, x, y); 
			x += 64;
			m_x++;
		}
		m_y++;
		y += 64;
	}
}
