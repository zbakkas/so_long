/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:43:23 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/26 20:56:25 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
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

static int	get_last_line(char **str)
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
//	printf("dddd===>%d\n", ft_strlen(str[0])-1);
	//printf("dddd===>%d\n", get_last_line(str) - 1);
	return (0);
}
static int ffff(char **str,int y ,int x,int *l)
{
	if(str[y][x] == 'C')
		(*l)++;
	str[y][x] = 'x';
	if(str[y][x+1]!= '1' && str[y][x+1]!= 'x')
		ffff(str,y,x+1,l);
	if(str[y][x-1]!= '1' &&str[y][x-1]!= 'x')
		ffff(str,y,x-1,l);
	if(str[y+1][x]!= '1'&&str[y+1][x]!= 'x')
		ffff(str,y+1,x,l);
	if(str[y-1][x]!= '1'&& str[y-1][x]!= 'x')
		ffff(str,y-1,x,l);

		return *l;
}
int mov_to_coins(char **s,int y ,int x,int *l)
{
	int tt =get_last_line(s);
	char **str = (char **)malloc((tt)*(sizeof(char *)));
	int i=0;
	int j;
    while (s[i]) 
	{
       str[i]=ft_strdup(s[i]);
		i++;
    }
	
	j = ffff(str,y,x,l);
	free_s(str);
	return j;
}
static int ffdor(char **str,int y ,int x,int *l)
{
	if(str[y][x] == 'E')
		(*l)++;
	str[y][x] = 'x';
	if(str[y][x+1]!= '1' && str[y][x+1]!= 'x')
		ffdor(str,y,x+1,l);
	if(str[y][x-1]!= '1' &&str[y][x-1]!= 'x')
		ffdor(str,y,x-1,l);
	if(str[y+1][x]!= '1'&&str[y+1][x]!= 'x')
		ffdor(str,y+1,x,l);
	if(str[y-1][x]!= '1'&& str[y-1][x]!= 'x')
		ffdor(str,y-1,x,l);

		return *l;
}
int mov_to_door(char **s,int y ,int x,int *l)
{
	int tt =get_last_line(s);
	char **str = (char **)malloc((tt)*(sizeof(char *)));
	int i=0;
	int j;
    while (s[i]) 
	{
       str[i]=ft_strdup(s[i]);
		i++;
    }

	j = ffdor(str,y,x,l);
	free_s(str);
	
	return j;
}
int check_characters(char **str)
{
	int x;
	int y;
	int p;
	int d;

	d =0;
	p =0;
	y =0;
	while (str[y])
	{
		x=0;
		while (str[y][x])
		{
			if(str[y][x]=='P')
				p++;
			if(str[y][x]=='E')
				d++;
			if(str[y][x]!='C'&&str[y][x]!='P'&&str[y][x]!='E'&&str[y][x]!='0'&&str[y][x]!='1')
				return 1;
			x++;
		}
		y++;
	}
	if(p !=1 || d != 1)
		return 1;
	return 0;
	
}
int check_image(t_map map)
{
	if(!map.player||!map.coins ||!map.wall||!map.wall_down||!map.wall_l||!map.wall_l_UP||!map.wall_o||!map.wall_R||!map.wall_R_UP||!map.door||!map.door_open||!map.p_id)
		return 1;

	return 0;
}
