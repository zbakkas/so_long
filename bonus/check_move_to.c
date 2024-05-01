/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:05:23 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/29 14:44:44 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ffdor(char **str, int y, int x, int *l)
{
	if (str[y][x] == 'E')
		(*l)++;
	str[y][x] = 'x';
	if (str[y][x + 1] != '1' && str[y][x + 1] != 'x')
		ffdor(str, y, x + 1, l);
	if (x - 1 >= 0 && str[y][x - 1] != '1' && str[y][x - 1] != 'x')
		ffdor(str, y, x - 1, l);
	if (str[y + 1][x] != '1' && str[y + 1][x] != 'x')
		ffdor(str, y + 1, x, l);
	if (y - 1 >= 0 && str[y - 1][x] != '1' && str[y - 1][x] != 'x')
		ffdor(str, y - 1, x, l);
	return (*l);
}

int	mov_to_door(char **s, int y, int x, int *l)
{
	int		tt;
	char	**str;
	int		i;
	int		j;

	tt = get_last_line(s);
	str = (char **)malloc((tt) * (sizeof(char *)) + 8);
	i = 0;
	while (tt > i)
	{
		str[i] = ft_strdup(s[i]);
		i++;
	}
	str[i] = NULL;
	j = ffdor(str, y, x, l);
	free_s(str);
	return (j);
}

int	check_move_to(t_map map)
{
	int	l;

	l = 0;
	if (map.coins_cou <= 0 || mov_to_coins(map.str, map.p_p[3], 
			map.p_p[2], &l) != map.coins_cou)
		return (1);
	l = 0;
	if (!mov_to_door(map.str, map.p_p[3], map.p_p[2], &l))
		return (1);
	return (0);
}

int	check_obj(t_map map)
{
	if (check_image(map))
		return (1);
	if (check_map_len(map.str) || check_walls(map.str)
		|| check_characters(map.str))
		return (1);
	return (0);
}
