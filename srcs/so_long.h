/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/22 22:18:20 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_map
{	
	char **maps;
	int y ;
	int x;
}t_map;

typedef struct s_game
{
	void *mlx;
	void *win;
}t_game;

int ft_strlen(char *str);
void ft_strncat(char *dst, char *src, int size);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	*ft_memfunc(void *b, void *s, int c, size_t len);
int count_lines(int fd);
char *get_path(char *filename);
int parsing_test(char *map[], int width, int height);
void start_position(char *map[],int *x, int *y);
int ext_test(char *filename);
int map_tests(char *filename, int *width, int *height);
#endif