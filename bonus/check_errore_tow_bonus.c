/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errore_tow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:34:26 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/01 11:58:59 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_characters_p(int p, int d)
{
	if (p != 1 || d != 1)
		return (1);
	return (0);
}

int	check_characters(char **str)
{
	int	x;
	int	y;
	int	p;
	int	d;

	d = 0;
	p = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == 'P')
				p++;
			if (str[y][x] == 'E')
				d++;
			if (str[y][x] != 'C' && str[y][x] != 'P' && str[y][x] != 'E' && 
				str[y][x] != '0' && str[y][x] != '1' && str[y][x] != 'M')
				return (1);
			x++;
		}
		y++;
	}
	return (check_characters_p(p, d));
}

int	check_image(t_map map)
{
	if (!map.player || !map.coins || !map.wall || !map.wall_down || !map.wall_l 
		|| !map.wall_l_up || !map.wall_o || !map.wall_r || !map.wall_r_up 
		|| !map.door || !map.door_open || !map.p_id || !map.enemy_an)
		return (1);
	return (0);
}
