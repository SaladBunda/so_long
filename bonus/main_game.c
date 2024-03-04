/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:03:53 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/29 22:03:53 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key_codes.h"

#define MLX_PUT mlx_put_image_to_window
#define MLX_S mlx_string_put

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

void	somethng(t_game *p, int par)
{
	if (par == 0)
	{
		p->p.y -= 64;
		p->mv++;
	}
	else if (par == 1)
	{
		p->p.y += 64;
		p->mv++;
	}
	else if (par == 2)
	{
		p->p.x -= 64;
		p->mv++;
	}
	else if (par == 3)
	{
		p->p.x += 64;
		p->mv++;
	}
}

void	draw_map(t_game g, t_map map, int i, int j)
{
	t_txts	img;

	load_textures(&img, g);
	while (map.ln[++i])
	{
		j = -1;
		while (map.ln[i][++j])
		{
			if (map.ln[i][j] == '1')
				MLX_PUT(g.mlx, g.win, img.w.img, j * 64, i * 64);
			else if (map.ln[i][j] == 'C')
			{
				MLX_PUT(g.mlx, g.win, img.f.img, j * 64, i * 64);
				MLX_PUT(g.mlx, g.win, img.c.img, j * 64, i * 64);
			}
			else
				MLX_PUT(g.mlx, g.win, img.f.img, j * 64, i * 64);
		}
	}
	if (g.p.c_col == g.map.coins)
		MLX_PUT(g.mlx, g.win, img.e_o.img, map.exit_x * 64, map.exit_y * 64);
	else
		MLX_PUT(g.mlx, g.win, img.e_c.img, map.exit_x * 64, map.exit_y * 64);
	MLX_PUT(g.mlx, g.win, img.p.img, g.p.x, g.p.y);
	MLX_S(g.mlx, g.win, (g.map.x - 2) * 64, 20, 0x00FF00, n_moves(g.mv));
}

int	f(int key, t_game *p)
{
	if (key == UK && p->map.ln[(p->p.y - 64) / 64][p->p.x / 64] != '1')
		somethng(p, 0);
	else if (key == DK && p->map.ln[(p->p.y + 64) / 64][p->p.x / 64] != '1')
		somethng(p, 1);
	else if (key == LK && p->map.ln[p->p.y / 64][(p->p.x - 64) / 64] != '1')
		somethng(p, 2);
	else if (key == RK && p->map.ln[p->p.y / 64][(p->p.x + 64) / 64] != '1')
		somethng(p, 3);
	else if (key == ESC_KEY)
		quit(p);
	if (p->map.ln[p->p.y / 64][p->p.x / 64] == 'C')
	{
		p->p.c_col++;
		p->map.ln[p->p.y / 64][p->p.x / 64] = '0';
	}
	if (p->p.c_col == p->map.coins 
		&& p->p.x == p->map.exit_x * 64 && p->p.y == p->map.exit_y * 64)
		quit(p);
	draw_map(*p, p->map, -1, -1);
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
	game.mv = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.x * 64, map.y * 64, "bunda");
	mlx_key_hook(game.win, f, &game);
	if (i++ == 0)
		draw_map(game, map, (-1), (-1));
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
