/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:39:31 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/29 10:51:25 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	p_palyer(int *p_p, char **maap)
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
			if (maap[m_y][m_x++] == 'P')
			{
				p_p[0] = x;
				p_p[1] = y;
				p_p[2] = m_x - 1;
				p_p[3] = m_y;
			}
			x += 64;
		}
		m_y++;
		y += 64;
	}
}

void	idle_f_f(int *idle_f)
{
	*idle_f = (*idle_f + 1) % 10;
}
