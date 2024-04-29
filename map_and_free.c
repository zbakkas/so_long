/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:45:19 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/28 19:56:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mapp_p(t_map *map)
{
	int	width;
	int	height;

	map->wall = mlx_xpm_file_to_image(map->mlx, "./image/wall.xpm", 
			&width, &height);
	map->wall_l = mlx_xpm_file_to_image(map->mlx, "./image/wall_ll.xpm",
			&width, &height);
	map->wall_r = mlx_xpm_file_to_image(map->mlx, "./image/wall_rr.xpm", 
			&width, &height);
	map->wall_down = mlx_xpm_file_to_image(map->mlx, "./image/wall_D.xpm",
			&width, &height);
	map->wall_o = mlx_xpm_file_to_image(map->mlx, "./image/wall_o.xpm", &width, 
			&height);
	map->wall_r_up = mlx_xpm_file_to_image(map->mlx, "./image/wall_R_up.xpm",
			&width, &height);
	map->wall_l_up = mlx_xpm_file_to_image(map->mlx, "./image/wall_l_up.xpm", 
			&width, &height);
	map->door = mlx_xpm_file_to_image(map->mlx, "./image/door.xpm", &width, 
			&height);
	map->door_open = mlx_xpm_file_to_image(map->mlx, "./image/door_open.xpm",
			&width, &height);
	map->bk = mlx_xpm_file_to_image(map->mlx, "./image/grr.xpm", &width,
			&height);
}

//map.direction = 0;// 0: up, 1: down, 2: left, 3: right

t_map	mapp(char *mapstr)
{
	t_map	map;

	map.fd = open(mapstr, O_RDONLY);
	map.lains = get_next_line(map.fd);
	map.str = ft_split(map.lains, '\n');
	free(map.lains);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, wind_size_x(map.str),
			wind_size_y(map.str), "map1");
	mapp_p(&map);
	map.idle_k = 0;
	map.idle_f = 0;
	map.direction = 0;
	map.player = player_an(map.mlx);
	map.frem_coins = 0;
	map.coins_cou = 0;
	map.p_id = player_idell(map.mlx);
	map.coins = coins_an(map.mlx);
	map.mov_cou = 0;
	return (map);
}

void	free_s(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		printf("%s\n", s[i]);
		free(s[i]);
		i++;
	}
	free(s);
}
