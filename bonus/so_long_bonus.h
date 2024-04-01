/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/29 21:18:13 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>      
# include <mlx.h>

# define MLX_PUT mlx_put_image_to_window 
# define MLX_S mlx_string_put
# define MLX_X mlx_xpm_file_to_image
# define MLX_D mlx_get_data_addr

# define UK 13
# define LK 0
# define RK 2
# define DK 1
# define ESC_KEY 53

typedef struct s_player
{
	int	x;
	int	y;
	int	c_col;
}	t_player;

typedef struct s_map
{
	char		**ln;
	int			y;
	int			x;
	int			coins;
	int			ex_x;
	int			ex_y;
	int			pos_x;
	int			pos_y;
	int			m_num;
	char		*fullpath;
	t_player	**m;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*a;
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
	t_img	pu;
	t_img	pd;
	t_img	pl;
	t_img	pr;
	t_img	p;
	t_img	co;
	t_img	c[12];
	t_img	e_c;
	t_img	e_o;
	t_img	m;
}	t_txts;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				mv;
	int				timer1;
	int				timer2;
	unsigned int	seed;
	int				m_num;
	int				coin_index;
	t_map			map;
	t_player		p;
	t_player		**m;
	t_txts			txt;
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
char	*get_path(char *filename, int i);
int		parsing_test(t_map *map);
void	start_position(t_map *map, int i, int j, int k);
int		map_tests(char *filename, t_map *map, int count_fd, int lines_fd);
void	main_game(t_map map);
void	ft_putnbr(int n);
int		quit(t_game *param, int option);
void	ft_putstr(char *str);
char	*n_moves(int n);
char	*ft_itoa(int n);
void	ft_settozero(int b[], int c, int len);
void	put_moves(t_game g);
void	m_enemy(t_game *g, int i);
int		get_fds(t_map *map, int *c_fd, int *l_fd, int *count);
int		draw_enemy(t_game *g);
void	draw_map(t_game g, t_map map, int i, int j);
void	load_textures(t_txts *x, t_game g);
void	output_enemy(t_game g);
void	initiate_var(t_game *g, t_map map);
int		fill_pixels(t_map *map, int i, int j);

#endif