/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:14:30 by zbakkas           #+#    #+#             */
/*   Updated: 2024/05/01 21:07:55 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map {
	void	**player;
	void	**p_id;
	void	*wall;
	void	*wall_l;
	void	*wall_r;
	void	*wall_down;
	void	*wall_o;
	void	*wall_r_up;
	void	*wall_l_up;
	void	*door;
	void	*door_open;
	void	*bk;
	void	*mlx;
	void	*win;
	void	**coins;
	char	*lains;
	char	**str;
	int		fd;
	int		mov_cou;
	int		p_p[4];
	int		idle_f;
	int		idle_k;
	int		direction;
	int		frem_coins;
	int		coins_cou;
}	t_map;

//player
void	**player_an(void *mlx);
void	**player_idell(void *mlx);
int		deal_key(int key, t_map *map);
void	p_palyer(int *p_p, char **maap);
void	idle_f_f(int *idle_f);
//coins
void	**coins_an(void *mlx);
int		get_conis_in_map(char **str);
void	get_coins(char **str, int *p_p, int *coins);
void	p_coins(t_map map);
//
void	p_ob(t_map map);
void	p_bk(t_map map);
void	p_door(void *mlx, void *win, t_map map, char **maap);
void	mapp(char *mapstr,t_map *map);
//
int		wind_size_x(char **str);
int		wind_size_y(char **str);
///errore
int		check_map_len(char **str);
int		check_walls(char **str);
int		mov_to_coins(char **str, int y, int x, int *l);
int		mov_to_door(char **s, int y, int x, int *l);
int		check_characters(char **str);
int		check_image(t_map map);
int		get_last_line(char **str);
///
void	free_s(char **s);
//void	free_v(void **s,void *mlx);

int		check_move_to(t_map map);
int		check_obj(t_map map);
//
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);

void	free_images(void *mlx, void **images, int num_images);
void	free_map(t_map *map, int i);
#endif