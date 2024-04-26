/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:19:49 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/25 21:21:18 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**player_an(void *mlx)
{
	int		width;
	int		height;
	void	**p;
	int		x;

	x = 0;
	p = (void **)malloc(4 * sizeof(void *));
	p[0] = mlx_xpm_file_to_image(mlx, "./image/player_0.xpm", &width, &height);
	if (!p[0])
		return NULL;
	p[1] = mlx_xpm_file_to_image(mlx, "./image/player_1.xpm", &width, &height);
	if (!p[1])
		return NULL;
	p[2] = mlx_xpm_file_to_image(mlx, "./image/player_2.xpm", &width, &height);
	if (!p[2])
		return NULL;
	p[3] = mlx_xpm_file_to_image(mlx, "./image/player_3.xpm", &width, &height);
	if (!p[3])
		return NULL;
	return (p);
}

void	**player_idell(void *mlx)
{
	int		width;
	int		height;
	void	**p_id;

	p_id = (void **)malloc(10 * sizeof(void *)); 
	p_id[0] = mlx_xpm_file_to_image(mlx, "./image/idle_0.xpm", &width, &height);
	if (!p_id[0])
		return (NULL);
	p_id[1] = mlx_xpm_file_to_image(mlx, "./image/idle_1.xpm", &width, &height);
	if (!p_id[1])
		return (NULL);
	p_id[2] = mlx_xpm_file_to_image(mlx, "./image/idle_2.xpm", &width, &height);
	if (!p_id[2])
		return (NULL);
	p_id[3] = mlx_xpm_file_to_image(mlx, "./image/idle_3.xpm", &width, &height);
	if (!p_id[3])
		return (NULL);
	p_id[4] = mlx_xpm_file_to_image(mlx, "./image/idle_4.xpm", &width, &height);
	if (!p_id[4])
		return (NULL);
	p_id[5] = mlx_xpm_file_to_image(mlx, "./image/idle_5.xpm", &width, &height);
	if (!p_id[5])
		return (NULL);
	p_id[6] = mlx_xpm_file_to_image(mlx, "./image/idle_6.xpm", &width, &height);
	if (!p_id[6])
		return (NULL);
	p_id[7] = mlx_xpm_file_to_image(mlx, "./image/idle_7.xpm", &width, &height);
	if (!p_id[7])
		return (NULL);
	p_id[8] = mlx_xpm_file_to_image(mlx, "./image/idle_8.xpm", &width, &height);
	if (!p_id[8])
		return (NULL);
	p_id[9] = mlx_xpm_file_to_image(mlx, "./image/idle_9.xpm", &width, &height);
	if (!p_id[9])
		return (NULL);
	return (p_id);
}

int	deal_key(int key ,t_map *map)
{
	// Unpack parameters  {mlx, win, player,str, p_p, &direction, &frame}
	if(key ==53)
		exit(0);

	if((key ==126 || key == 13)&& (*map).str[(*map).p_p[3]-1][(*map).p_p[2]]!='1')
	{
		map->mov_cou++;
		(*map).idle_k=1;
		(*map).direction = 0;
		(*map).p_p[3]-=1;
		(*map).p_p[1] -= 64; // up   
	}
	if((key ==125 ||key ==1)&&(*map).str[(*map).p_p[3]+1][(*map).p_p[2]]!='1')
	{
		map->mov_cou++;
		(*map).idle_k=1;
		(*map).direction = 1; // Down
		(*map).p_p[3]+=1;
		(*map).p_p[1] += 64; 
	}
	if((key ==123|| key ==0)&&(*map).str[(*map).p_p[3]][(*map).p_p[2]-1]!='1')
	{
		map->mov_cou++;
		(*map).idle_k=1;
		(*map).direction = 2; // Left
		(*map).p_p[2]-=1;
		(*map).p_p[0] -= 64; 
	}
	if((key ==124|| key == 2)&&(*map).str[(*map).p_p[3]][(*map).p_p[2]+1]!='1')
	{
		map->mov_cou++;
		(*map).idle_k=1;
		(*map).direction = 3; // Right
		(*map).p_p[2]+=1;
		(*map).p_p[0] += 64; 
	}
	printf("%d\n",map->mov_cou);
	get_coins((*map).str, (*map).p_p, &(*map).coins_cou);
	mlx_clear_window((*map).mlx, map->win);
	return (0);
}

void	p_palyer(void *mlx, void *win, int *p_p, char **maap)
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
			if (maap[m_y][m_x] == 'P')
			{
				p_p[0] = x;
				p_p[1] = y;
				p_p[2] = m_x;
				p_p[3] = m_y;
			}
			x += 64;
			m_x++;
		}
		m_y++;
		y += 64;
	}
}

void	idle_f_f(int *idle_f)
{
	*idle_f = (*idle_f + 1) % 10;
}
