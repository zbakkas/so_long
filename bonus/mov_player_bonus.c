/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:19:49 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/07 21:23:13 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		return (free(p), NULL);
	p[1] = mlx_xpm_file_to_image(mlx, "./image/player_1.xpm", &width, &height);
	if (!p[1])
		return (free(p), NULL);
	p[2] = mlx_xpm_file_to_image(mlx, "./image/player_2.xpm", &width, &height);
	if (!p[2])
		return (free(p), NULL);
	p[3] = mlx_xpm_file_to_image(mlx, "./image/player_3.xpm", &width, &height);
	if (!p[3])
		return (free(p), NULL);
	return (p);
}

int	player_idell_p(void *mlx, void **p_id)
{
	int		width;
	int		height;

	p_id[4] = mlx_xpm_file_to_image(mlx, "./image/idle_4.xpm", &width, &height);
	if (!p_id[4])
		return (0);
	p_id[5] = mlx_xpm_file_to_image(mlx, "./image/idle_5.xpm", &width, &height);
	if (!p_id[5])
		return (0);
	p_id[6] = mlx_xpm_file_to_image(mlx, "./image/idle_6.xpm", &width, &height);
	if (!p_id[6])
		return (0);
	p_id[7] = mlx_xpm_file_to_image(mlx, "./image/idle_7.xpm", &width, &height);
	if (!p_id[7])
		return (0);
	p_id[8] = mlx_xpm_file_to_image(mlx, "./image/idle_8.xpm", &width, &height);
	if (!p_id[8])
		return (0);
	p_id[9] = mlx_xpm_file_to_image(mlx, "./image/idle_9.xpm", &width, &height);
	if (!p_id[9])
		return (0);
	return (1);
}

void	**player_idell(void *mlx)
{
	int		width;
	int		height;
	void	**p_id;

	p_id = (void **)malloc(10 * sizeof(void *)); 
	p_id[0] = mlx_xpm_file_to_image(mlx, "./image/idle_0.xpm", &width, &height);
	if (!p_id[0])
		return (free(p_id), NULL);
	p_id[1] = mlx_xpm_file_to_image(mlx, "./image/idle_1.xpm", &width, &height);
	if (!p_id[1])
		return (free(p_id), NULL);
	p_id[2] = mlx_xpm_file_to_image(mlx, "./image/idle_2.xpm", &width, &height);
	if (!p_id[2])
		return (free(p_id), NULL);
	p_id[3] = mlx_xpm_file_to_image(mlx, "./image/idle_3.xpm", &width, &height);
	if (!p_id[3])
		return (free(p_id), NULL);
	if (!player_idell_p(mlx, p_id))
		return (free(p_id), NULL);
	return (p_id);
}

int	deal_key_to(int key, t_map *map)
{
	if ((key == 123 || key == 0) 
		&& (*map).str[(*map).p_p[3]][(*map).p_p[2] - 1] != '1')
	{
		map->mov_cou++;
		(*map).idle_k = 1;
		(*map).direction = 2;
		(*map).p_p[2] -= 1;
		(*map).p_p[0] -= 64; 
	}
	if ((key == 124 || key == 2) 
		&& (*map).str[(*map).p_p[3]][(*map).p_p[2] + 1] != '1')
	{
		map->mov_cou++;
		(*map).idle_k = 1;
		(*map).direction = 3;
		(*map).p_p[2] += 1;
		(*map).p_p[0] += 64; 
	}
	tt_ex((*map).str, map);
	return (0);
}

int	deal_key(int key, t_map *map)
{
	if (key == 53)
		free_map(map, 0);
	if ((key == 126 || key == 13) && 
		(*map).str[(*map).p_p[3] - 1][(*map).p_p[2]] != '1')
	{
		map->mov_cou++;
		(*map).idle_k = 1;
		(*map).direction = 0;
		(*map).p_p[3] -= 1;
		(*map).p_p[1] -= 64; 
	}
	if ((key == 125 || key == 1) 
		&& (*map).str[(*map).p_p[3] + 1][(*map).p_p[2]] != '1')
	{
		map->mov_cou++;
		(*map).idle_k = 1;
		(*map).direction = 1;
		(*map).p_p[3] += 1;
		(*map).p_p[1] += 64; 
	}
	deal_key_to(key, map);
	get_coins((*map).str, (*map).p_p, &(*map).coins_cou);
	return (0);
}
