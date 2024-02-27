/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/27 22:29:51 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	char	**lines;
	int		y;
	int		x;
	int		coins;
	int		exit_x;
	int		exit_y;
	int		pos_x;
	int		pos_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		en;
	int		wth;
	int		hht;
}	t_img;

typedef struct s_txts
{
	t_img	w;
	t_img	f;
	t_img	p;
	t_img	c;
	t_img	e_c;
	t_img	e_o;
}	t_txts;

typedef struct s_player
{
	int	x;
	int	y;
	int	c_col;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	p;
}	t_game;

int		ft_strlen(char *str);
void	ft_strncat(char *dst, char *src, int size);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	*ft_memfunc(void *b, void *s, int c, size_t len);
void	ft_putchar(int c);
int		count_lines(int fd);
char	*get_path(char *filename);
int		parsing_test(t_map *map);
void	start_position(t_map *map);
int		map_tests(char *filename, t_map *map, int count_fd, int lines_fd);
void	main_game(t_map map);

#endif