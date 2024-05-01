/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_tow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:53:02 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/01 12:09:06 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	allocation_enemy(t_map *map)
{
	int	i;
	int	t;

	i = 0;
	t = coun_enemy(*map);
	map->enmey_p = (int **)malloc((t + 1) * sizeof(int *));
	map->enemy_f = malloc((t) * sizeof(int *));
	while (t > i)
		map->enmey_p[i++] = malloc((5) * sizeof(int ));
}

void	free_enemy(t_map *map)
{
	int	t;
	int	i;

	i = 0;
	t = coun_enemy(*map);
	while (t > i)
		free(map->enmey_p[i++]);
	free(map->enmey_p);
}

int	coun_enemy(t_map map)
{
	int	x;
	int	y;
	int	m_x;
	int	m_y;
	int	i;

	y = 0;
	m_y = 0;
	i = 0;
	while (map.str[m_y])
	{
		m_x = 0;
		x = 0;
		while (map.str[m_y][m_x])
		{
			if (map.str[m_y][m_x] == 'M')
				i++;
			m_x++;
			x += 64;
		}
		m_y++;
		y += 64;
	}
	return (i);
}

void	put_enemy(t_map *map)
{
	int	i;
	int	t;

	t = coun_enemy(*map);
	i = 0;
	while (t > i)
	{
		mlx_put_image_to_window((*map).mlx, (*map).win, 
			(*map).enemy_an[map->enemy_f[i]], (*map).enmey_p[i][0],
			(*map).enmey_p[i][1]);
		i++;
	}
}
