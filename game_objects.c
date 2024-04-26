/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:58:00 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/26 21:08:00 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void p_ob(t_map map)
{
	int x=0;
	int y=0;
	int m_x=0;
	int m_y=0;
	while (map.str[m_y])
	{
		m_x=0;
		x=0;
		while (map.str[m_y][m_x])
		{
			mlx_put_image_to_window(map.mlx, map.win, map.bk, x, y);
			if(map.str[m_y][m_x]=='1'&&m_y == 0&& !map.str[m_y][m_x+1])
				mlx_put_image_to_window(map.mlx, map.win, map.wall_R_UP, x, y); 
			else if(map.str[m_y][m_x]=='1'&&m_y == 0&& m_x ==0)
				mlx_put_image_to_window(map.mlx, map.win, map.wall_l_UP, x, y); 
			else if(map.str[m_y][m_x]=='1' && m_y == 0)
				mlx_put_image_to_window(map.mlx, map.win, map.wall, x, y); 
			else if(map.str[m_y][m_x]=='1' && m_x == 0 && m_y!=0 && map.str[m_y+1])
				mlx_put_image_to_window(map.mlx, map.win, map.wall_l, x, y); 
			else if(map.str[m_y][m_x]=='1' && !map.str[m_y+1])
				mlx_put_image_to_window(map.mlx, map.win, map.wall_down, x, y); 
			else if(map.str[m_y][m_x]=='1' && !map.str[m_y][m_x+1])
				mlx_put_image_to_window(map.mlx, map.win, map.wall_R, x, y); 
			else if(map.str[m_y][m_x]=='1')
				mlx_put_image_to_window(map.mlx, map.win, map.wall_o, x, y); 
			x+=64;
			m_x++;
		}
		m_y++;
		y+=64;  
	}
}

void p_door(void *mlx, void *win, t_map map,char **maap)
{
	int x=0;
	int y=0;
	int m_x=0;
	int m_y=0;
	while (maap[m_y])
	{
		m_x=0;
		x=0;
		while (maap[m_y][m_x])
		{
			if(maap[m_y][m_x]=='E')
			{
				if(map.coins_cou <=0)
					mlx_put_image_to_window(mlx, win, map.door_open, x, y); 
				else
					mlx_put_image_to_window(mlx, win, map.door, x, y); 
			}
			x+=64;
			m_x++;
		}
		m_y++;
		y+=64;  
	}
}
t_map mapp()
{
	int width;
	int height;
	t_map map;
	
	map.fd = open("map1.ber", O_RDONLY);
	map.str =ft_split(get_next_line(map.fd),'\n');
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, wind_size_x(map.str), wind_size_y(map.str), "map1");
	map.wall = mlx_xpm_file_to_image(map.mlx, "./image/wall.xpm", &width, &height);//
	map.wall_l = mlx_xpm_file_to_image(map.mlx, "./image/wall_ll.xpm", &width, &height);//
	map.wall_R = mlx_xpm_file_to_image(map.mlx, "./image/wall_rr.xpm", &width, &height);//
	map.wall_down = mlx_xpm_file_to_image(map.mlx, "./image/wall_D.xpm", &width, &height);//
	map.wall_o = mlx_xpm_file_to_image(map.mlx, "./image/wall_o.xpm", &width, &height);//
	map.wall_R_UP = mlx_xpm_file_to_image(map.mlx, "./image/wall_R_up.xpm", &width, &height);//
	map.wall_l_UP = mlx_xpm_file_to_image(map.mlx, "./image/wall_l_up.xpm", &width, &height);//
	map.door = mlx_xpm_file_to_image(map.mlx, "./image/door.xpm", &width, &height);//
	map.door_open = mlx_xpm_file_to_image(map.mlx, "./image/door_open.xpm", &width, &height);//
	map.bk =mlx_xpm_file_to_image(map.mlx,"./image/grr.xpm",&width,&height);
	map.idle_k=0;
	map.idle_f=0;
	map.direction = 0;// 0: up, 1: down, 2: left, 3: right
	map.player = player_an(map.mlx);
	map.frem_coins =0;
	map.coins_cou =0;
	map.p_id = player_idell(map.mlx);
	map.coins =coins_an(map.mlx);
	map.mov_cou =0;
	return map;
}
void	free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
void	free_v(void **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}