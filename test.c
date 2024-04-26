/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:45:26 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/26 21:17:45 by zbakkas          ###   ########.fr       */
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
int close_button_click(int key, void *param)
{
        exit(0); // Exit the program when the close button is clicked
    return (0);
}

int	main()
{
	t_map	map;
	int		counter;

	map = mapp();
	if(check_image(map))
		return (printf("errore"), 0);
	if (check_map_len(map.str) || check_walls(map.str)||check_characters(map.str))
		return (printf("errore"), 0);
	counter = 2;

	
	map.coins_cou = get_conis_in_map(map.str);
	p_ob(map);
	p_palyer(map.mlx, map.win, map.p_p, map.str);
	p_door(map.mlx, map.win, map, map.str);
	p_coins(map);
	int l =0;
	if (map.coins_cou <=0 || mov_to_coins(map.str,map.p_p[3],map.p_p[2],&l)!=map.coins_cou )
		return (printf("errore"), 0);
	l =0;
	if (!mov_to_door(map.str,map.p_p[3],map.p_p[2],&l))
		return (printf("errore"), 0);
	//printf("==>%d\n",);
	mlx_hook(map.win, 2, 1L << 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, close_button_click, NULL);
	while (1)
	{
		mlx_clear_window(map.mlx, map.win);
		idle_f_f(&map.idle_f);
		p_ob(map);
		p_door(map.mlx, map.win, map, map.str);
		if (map.idle_k)
		{
			mlx_put_image_to_window(map.mlx, map.win, map.player[map.direction], map.p_p[0], map.p_p[1]);
			counter--;
			if (counter <= 0)
			{
				counter = 2;
				map.idle_k = 0;
			}
		}
		else
			mlx_put_image_to_window(map.mlx, map.win, map.p_id[map.idle_f], map.p_p[0], map.p_p[1]);
		map.frem_coins = (map.frem_coins + 1) % 6;
		p_coins(map);
		tt_ex(map.str, map);
		mlx_do_sync(map.mlx);
	}
	free_s(map.str);
	//free_v(map.player);
	//free_v(map.coins);
	//free_v(map.p_id);
}
