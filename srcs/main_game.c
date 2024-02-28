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

#define MLX_PUT mlx_put_image_to_window

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
				MLX_PUT(g.mlx, g.win, img.w.img, j * 64, i * 64);
			else if (map.lines[i][j] == 'C')
			{
				MLX_PUT(g.mlx, g.win, img.f.img, j * 64, i * 64);
				MLX_PUT(g.mlx, g.win, img.c.img, j * 64, i * 64);
			}
			else
				MLX_PUT(g.mlx, g.win, img.f.img, j * 64, i * 64);
		}
	}
	MLX_PUT(g.mlx, g.win, img.p.img, g.p.x, g.p.y);
	if (g.p.c_col == g.map.coins)
		MLX_PUT(g.mlx, g.win, img.e_o.img, map.exit_x * 64, map.exit_y * 64);
	else
		MLX_PUT(g.mlx, g.win, img.e_c.img, map.exit_x * 64, map.exit_y * 64);
}

int	quit(t_game *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(1);
}

int	f(int key, t_game *pm)
{
	if (key == UP_KEY && 
		pm->map.lines[(pm->p.y - 64) / 64][pm->p.x / 64] != '1')
		pm->p.y -= 64;
	else if (key == DOWN_KEY
		&& pm->map.lines[(pm->p.y + 64) / 64][pm->p.x / 64] != '1')
		pm->p.y += 64;
	else if (key == LEFT_KEY
		&& pm->map.lines[pm->p.y / 64][(pm->p.x - 64) / 64] != '1')
		pm->p.x -= 64;
	else if (key == RIGHT_KEY
		&& pm->map.lines[pm->p.y / 64][(pm->p.x + 64) / 64] != '1')
		pm->p.x += 64;
	else if (key == ESC_KEY)
		quit(pm);
	if (pm->map.lines[pm->p.y / 64][pm->p.x / 64] == 'C')
	{
		pm->p.c_col++;
		pm->map.lines[pm->p.y / 64][pm->p.x / 64] = '0';
	}
	if (pm->p.c_col == pm->map.coins 
		&& pm->p.x == pm->map.exit_x * 64 && pm->p.y == pm->map.exit_y * 64)
		quit(pm);
	draw_map(*pm, pm->map, -1, -1);
	return (0);
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
