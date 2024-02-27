/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:49:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 01:49:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key_codes.h"

void	load_textures(t_txts *x, t_game g)
{
	x->w.img = mlx_xpm_file_to_image(g.mlx, "./textures/W.xpm", 
			&x->w.wth, &x->w.hht);
	x->w.addr = mlx_get_data_addr(x->w.img, &x->w.bpp, &x->w.ll, &x->w.en);
	x->f.img = mlx_xpm_file_to_image(g.mlx, "./textures/f.xpm",
			&x->f.wth, &x->f.hht);
	x->f.addr = mlx_get_data_addr(x->f.img, &x->f.bpp, &x->f.ll, &x->f.en);
	x->p.img = mlx_xpm_file_to_image(g.mlx, "./textures/p.xpm",
			&x->p.wth, &x->p.hht);
	x->p.addr = mlx_get_data_addr(x->p.img, &x->p.bpp, &x->p.ll, &x->p.en);
	x->c.img = mlx_xpm_file_to_image(g.mlx, "./textures/c.xpm",
			&x->c.wth, &x->c.hht);
	x->c.addr = mlx_get_data_addr(x->c.img, &x->c.bpp, &x->c.ll, &x->c.en);
	x->e_c.img = mlx_xpm_file_to_image(g.mlx, "./textures/ec.xpm",
			&x->e_c.wth, &x->e_c.hht);
	x->e_c.addr = mlx_get_data_addr(x->e_c.img, &x->e_c.bpp,
			&x->e_c.ll, &x->e_c.en);
	x->e_o.img = mlx_xpm_file_to_image(g.mlx, "./textures/eo.xpm",
			&x->e_o.wth, &x->e_o.hht);
	x->e_o.addr = mlx_get_data_addr(x->e_o.img, &x->e_o.bpp,
			&x->e_o.ll, &x->e_o.en);
}

void	draw_map(t_game g, t_map map, int i, int j)
{
	t_txts	img;

	load_textures(&img, g);
	while (map.lines[++i])
	{
		j = -1;
		while (map.lines[i][++j])
		{
			if (map.lines[i][j] == '1')
				mlx_put_image_to_window(g.mlx, g.win, 
					img.w.img, j * 64, i * 64);
			else if (map.lines[i][j] == 'C')
			{
				mlx_put_image_to_window(g.mlx, g.win,
					img.f.img, j * 64, i * 64);
				mlx_put_image_to_window(g.mlx, g.win,
					img.c.img, j * 64, i * 64);
			}
			else
				mlx_put_image_to_window(g.mlx, g.win,
					img.f.img, j * 64, i * 64);
		}
	}
	mlx_put_image_to_window(g.mlx, g.win, img.p.img, g.p.x, g.p.y);
	if (g.p.c_col == g.map.coins)
		mlx_put_image_to_window(g.mlx, g.win, img.e_o.img, map.exit_x * 64, map.exit_y * 64);
	else
		mlx_put_image_to_window(g.mlx, g.win, img.e_c.img, map.exit_x * 64, map.exit_y * 64);
}

int f(int key, t_game *param)
{
	if(key == UP_KEY && param->map.lines[(param->p.y-64)/64][param->p.x/64]!='1')
		param->p.y-=64;
	else if(key == DOWN_KEY  && param->map.lines[(param->p.y+64)/64][param->p.x/64]!='1')
		param->p.y+=64;
	else if(key == LEFT_KEY && param->map.lines[param->p.y/64][(param->p.x-64)/64]!='1')
		param->p.x-=64;
	else if (key == RIGHT_KEY && param->map.lines[param->p.y/64][(param->p.x+64)/64]!='1')
		param->p.x+=64;
	else if(key == ESC_KEY )
	{
		mlx_destroy_window(param->mlx,param->win);
		exit(1);
	}
	if(param->map.lines[param->p.y/64][param->p.x/64]=='C')
	{
		param->p.c_col++;
		param->map.lines[param->p.y/64][param->p.x/64]='0';
	}
	draw_map(*param, param->map, -1, -1);
	return (0);
}

int	quit(t_game *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(1);
}

void	main_game(t_map map)
{
	t_game	game;
	int		i;

	i = 0;
	game.map = map;
	game.p.x = map.pos_x * 64;
	game.p.y = map.pos_y * 64;
	game.p.c_col = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.x * 64, map.y * 64, "bunda");
	mlx_key_hook(game.win, f, &game);
	if (i++ == 0)
		draw_map(game, map, (-1), (-1));
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
