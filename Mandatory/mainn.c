/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:45:26 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/07 21:08:10 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tt_ex(char **str, t_map *map)
{
	if (map->coins_cou <= 0 
		&& str[map->p_p[3]][map->p_p[2]] == 'E')
	{
		write(1, "Win\n", 4);
		free_map(map, 0);
	}
}

int	close_button_click(t_map *map)
{
	free_map(map, 0);
	return (0);
}

void	whilee_loop(t_map *map, int *counter)
{
	mlx_clear_window((*map).mlx, (*map).win);
	p_bk(*map);
	idle_f_f(&(*map).idle_f);
	p_ob((*map));
	p_door((*map).mlx, (*map).win, *map, (*map).str);
	if ((*map).idle_k)
	{
		mlx_put_image_to_window((*map).mlx, (*map).win, 
			(*map).player[(*map).direction], (*map).p_p[0], (*map).p_p[1]);
		(*counter)--;
		if (*counter <= 0)
		{
			*counter = 2;
			(*map).idle_k = 0;
		}
	}
	else
		mlx_put_image_to_window((*map).mlx, (*map).win, 
			(*map).p_id[(*map).idle_f], (*map).p_p[0], (*map).p_p[1]);
	(*map).frem_coins = ((*map).frem_coins + 1) % 6;
	p_coins((*map));
	mlx_do_sync((*map).mlx);
}

void	free_images(void *mlx, void **images, int num_images)
{
	int	i;

	i = 0;
	while (i < num_images)
	{
		if (images[i])
			mlx_destroy_image(mlx, images[i]);
		i++;
	}
	free(images);
}

int	main( int arv, char **arc)
{
	t_map	map;
	int		counter;

	if (arv > 2 || arv < 2 || ft_strnstr(arc[1]))
		return (write(2, "Error\n", 6), 0);
	mapp(arc[1], &map);
	counter = 2;
	if (check_obj(map) || wind_size_x(map.str) > 2560 
		|| wind_size_y(map.str) > 1408)
		free_map(&map, 1);
	map.coins_cou = get_conis_in_map(map.str);
	p_palyer(map.p_p, map.str);
	if (check_move_to(map))
		free_map(&map, 1);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, close_button_click, &map);
	while (1)
		whilee_loop(&map, &counter);
	free_map(&map, 0);
}
