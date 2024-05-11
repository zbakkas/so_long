/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:11 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/07 21:21:44 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	p_enemy(int **p_e, char **maap, int i)
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
			if (maap[m_y][m_x++] == 'M')
			{
				p_e[i][0] = x;
				p_e[i][1] = y;
				p_e[i][2] = m_x - 1;
				p_e[i++][3] = m_y;
			}
			x += 64;
		}
		m_y++;
		y += 64;
	}
}

void	**enemyy_an(void *mlx)
{
	int		width;
	int		height;
	void	**p;
	int		x;

	x = 0;
	p = (void **)malloc(2 * sizeof(void *));
	p[0] = mlx_xpm_file_to_image(mlx, "./image/ghost_l.xpm", &width, &height);
	if (!p[0])
		return (free(p), NULL);
	p[1] = mlx_xpm_file_to_image(mlx, "./image/ghost_r.xpm", &width, &height);
	if (!p[1])
		return (free(p), NULL);
	return (p);
}

static void	move_enemy(t_map *map, int i)
{
	if (map->enemy_f[i] == 1 && 
		map->str[map->enmey_p[i][3]][map->enmey_p[i][2] + 1] != '1')
	{
		map->enmey_p[i][2]++;
		map->enmey_p[i][0] += 64;
	}
	else
		map->enemy_f[i] = 0;
	if (map->enemy_f[i] == 0 && 
		map->str[map->enmey_p[i][3]][map->enmey_p[i][2] - 1] != '1')
	{
		map->enmey_p[i][2]--;
		map->enmey_p[i][0] -= 64;
	}
	else
		map->enemy_f[i] = 1;
	if (((map->enemy_f[i] == 1 && map->p_p[2] >= map->enmey_p[i][2] - 1 && 
			map->p_p[2] <= map->enmey_p[i][2]) || (map->enemy_f[i] == 0 && 
			map->p_p[2] >= map->enmey_p[i][2] &&
			map->p_p[2] <= map->enmey_p[i][2] + 2))
			&& map->p_p[3] == map->enmey_p[i][3])
	{
		write(1, "lose\n", 4);
		free_map(map, 0);
	}
}

void	mov_enemis(t_map *map)
{
	int	i;
	int	t;

	t = coun_enemy(*map);
	i = 0;
	while (t > i)
	{
		move_enemy(map, i);
		i++;
	}
}

void	p_enemeis(t_map map)
{
	int		tt;
	char	**str;
	int		i;

	tt = get_last_line(map.str);
	str = (char **)malloc((tt) * (sizeof(char *)) + 8);
	i = 0;
	while (tt > i)
	{
		str[i] = ft_strdup(map.str[i]);
		i++;
	}
	str[i] = NULL;
	i = 0;
	p_enemy(map.enmey_p, str, i);
	free_s(str);
}
