/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:14:30 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/26 21:08:48 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "libft/libft.h"

typedef struct	s_map {
 void *wall;
 void *wall_l;
 void *wall_R ;
 void *wall_down ;
 void *wall_o ;
 void *wall_R_UP ;
 void *wall_l_UP ;
 void *door ;
 void *door_open ;
// void *coins ;
 void **player;
 void *bk;
 int p_p[4];
int idle_f;
int idle_k;
int direction;
int frem_coins;
int coins_cou;

    void *mlx;
    void *win;
    int fd;
    char **str;
    void **p_id;
    void **coins;
    int mov_cou;

}				t_map;
//player
void **player_an(void * mlx);
void **player_idell(void * mlx);
int deal_key(int key ,t_map *map);
void p_palyer(void *mlx, void *win,int *p_p ,char **maap);
void idle_f_f(int *idle_f);
//coins
void **coins_an(void * mlx);
int get_conis_in_map(char **str);
void get_coins(char **str,int *p_p,int *coins);
void	p_coins(t_map map);
//
void p_ob(t_map map);
void p_door(void *mlx, void *win, t_map map,char **maap);
t_map mapp();
//
int wind_size_x(char ** str);
int wind_size_y(char ** str);
///errore
int	check_map_len(char **str);
int	check_walls(char **str);
int mov_to_coins(char **str,int y ,int x,int *l);
int mov_to_door(char **s,int y ,int x,int *l);
int check_characters(char **str);
int check_image(t_map map);
///
void	free_s(char **s);
void	free_v(void **s);
#endif