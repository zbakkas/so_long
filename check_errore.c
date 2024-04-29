/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:43:23 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/28 19:53:15 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_len(char **str)
{
	int	x;
	int	l;

	x = 0;
	if (str[0])
		l = ft_strlen(str[x]);
	while (str[x])
	{
		if (l != ft_strlen(str[x]))
			return (1);
		x++;
	}
	return (0);
}

int	get_last_line(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	check_walls(char **str)
{
	int	x;

	x = 0;
	while (str[0][x])
		if (str[0][x++] != '1')
			return (1);
	x = 0;
	while (str[x])
		if (str[x++][0] != '1')
			return (1);
	x = 0;
	while (str[get_last_line(str) - 1][x])
		if (str[get_last_line(str) - 1][x++] != '1')
			return (1);
	x = 0;
	while (str[x] && str[x][ft_strlen(str[0]) - 1])
		if (str[x++][ft_strlen(str[0]) - 1] != '1')
			return (1);
	return (0);
}

static int	ffff(char **str, int y, int x, int *l)
{
	if (str[y][x] == 'C')
		(*l)++;
	str[y][x] = 'x';
	if (str[y][x + 1] != '1' && str[y][x + 1] != 'x')
		ffff(str, y, x + 1, l);
	if (str[y][x - 1] != '1' && str[y][x - 1] != 'x')
		ffff(str, y, x - 1, l);
	if (str[y + 1][x] != '1' && str[y + 1][x] != 'x')
		ffff(str, y + 1, x, l);
	if (str[y - 1][x] != '1' && str[y - 1][x] != 'x')
		ffff(str, y - 1, x, l);
	return (*l);
}

int	mov_to_coins(char **s, int y, int x, int *l)
{
	int		tt;
	char	**str;
	int		i;
	int		j;

	tt = get_last_line(s);
	str = (char **)malloc((tt) * (sizeof(char *)));
	i = 0;
	while (s[i])
	{
		str[i] = ft_strdup(s[i]);
		i++;
	}
	str[i] = NULL;
	j = ffff(str, y, x, l);
	free_s(str);
	return (j);
}
