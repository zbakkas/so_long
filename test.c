/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:45:26 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/29 09:44:00 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tt_ex(char **str, t_map map)
{
	if (map.coins_cou <= 0 
		&& str[map.p_p[3]][map.p_p[2]] == 'E')
	{
		printf("win\n");
		exit(0);
	}
}

int	close_button_click(void)
{
	exit(0);
	return (0);
}

void	ll(void)
{
	system("leaks so_long");
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
	tt_ex((*map).str, (*map));
	mlx_do_sync((*map).mlx);
}

int	main( int arv, char **arc)
{
	//atexit(ll);
	t_map	map;
	int		counter;

	if (arv > 2 || arv < 2)
		return (printf("erro2re"),0);
	map = mapp(arc[1]);
	counter = 2;
	if (check_obj(map))
		return (free(map.player), free(map.coins),
			free(map.p_id), free_s(map.str), printf("errore"), 0);
	map.coins_cou = get_conis_in_map(map.str);
	p_palyer(map.p_p, map.str);
	if (check_move_to(map))
		return (free(map.player), free(map.coins), free(map.p_id),
			free_s(map.str), printf("erro1re"), 0);
	mlx_hook(map.win, 2, 1L << 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, close_button_click, NULL);
	while (1)
		whilee_loop(&map, &counter);
}
