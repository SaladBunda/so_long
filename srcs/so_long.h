/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/26 16:42:30 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct s_map
{	
	char **lines;
	int y;
	int x;
	int coins;
	int exit_x;
	int exit_y;
	int pos_x;
	int pos_y;
}t_map;

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
} t_img;

typedef struct s_txts
{
	t_img wall;
	t_img floor;
	t_img plyr;
	t_img coins;
	t_img exit_c;
	t_img exit_o;
} t_txts;

typedef struct s_player
{
	int x;
	int y;
	int c_col;
} t_player;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_map map;
	t_player p;
}t_game;

int ft_strlen(char *str);
void ft_strncat(char *dst, char *src, int size);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	*ft_memfunc(void *b, void *s, int c, size_t len);
void ft_putchar(int c);
int count_lines(int fd);
char *get_path(char *filename);
int parsing_test(t_map *map);
void start_position(t_map *map);
int ext_test(char *filename);
int map_tests(char *filename, t_map *map);
void main_game(t_map map);

#endif