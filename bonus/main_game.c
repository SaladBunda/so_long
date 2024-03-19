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

#include "so_long_bonus.h"
#include "key_codes.h"

void	load_player(t_txts *x, t_game g)
{
	x->pu.img = MLX_XPM(g.mlx, "./textures/pu.xpm", &x->pu.wth, &x->pu.hht);
	x->pu.addr = MLX_DATA(x->pu.img, &x->pu.bpp, &x->pu.ll, &x->pu.en);
	x->pd.img = MLX_XPM(g.mlx, "./textures/pd.xpm", &x->pd.wth, &x->pd.hht);
	x->pd.addr = MLX_DATA(x->pd.img, &x->pd.bpp, &x->pd.ll, &x->pd.en);
	x->pr.img = MLX_XPM(g.mlx, "./textures/pr.xpm", &x->pr.wth, &x->pr.hht);
	x->pr.addr = MLX_DATA(x->pr.img, &x->pr.bpp, &x->pr.ll, &x->pr.en);
	x->pl.img = MLX_XPM(g.mlx, "./textures/pl.xpm", &x->pl.wth, &x->pl.hht);
	x->pl.addr = MLX_DATA(x->pl.img, &x->pl.bpp, &x->pl.ll, &x->pl.en);
	x->p=x->pu;
}

void	load_textures(t_txts *x, t_game g)
{
	x->w.img = MLX_XPM(g.mlx, "./textures/W.xpm", &x->w.wth, &x->w.hht);
	x->w.addr = MLX_DATA(x->w.img, &x->w.bpp, &x->w.ll, &x->w.en);
	x->f.img = MLX_XPM(g.mlx, "./textures/f.xpm", &x->f.wth, &x->f.hht);
	x->f.addr = MLX_DATA(x->f.img, &x->f.bpp, &x->f.ll, &x->f.en);
	x->c[0].img = MLX_XPM(g.mlx, "./textures/c.xpm", &x->c[0].wth, &x->c[0].hht);
	x->c[0].addr = MLX_DATA(x->c[0].img, &x->c[0].bpp, &x->c[0].ll, &x->c[0].en);
	x->m.img = MLX_XPM(g.mlx, "./textures/M.xpm", &x->m.wth, &x->m.hht);
	x->m.addr = MLX_DATA(x->m.img, &x->m.bpp, &x->m.ll, &x->m.en);
	x->e_c.img = MLX_XPM(g.mlx, "./textures/ec.xpm", &x->e_c.wth, &x->e_c.hht);
	x->e_c.addr = MLX_DATA(x->e_c.img, &x->e_c.bpp, &x->e_c.ll, &x->e_c.en);
	x->e_o.img = MLX_XPM(g.mlx, "./textures/eo.xpm", &x->e_o.wth, &x->e_o.hht);
	x->e_o.addr = MLX_DATA(x->e_o.img, &x->e_o.bpp, &x->e_o.ll, &x->e_o.en);
	load_player(x,g);
}

// void load_coins(t_txts *x, t_game g);

void	somethng(t_game *p, int par)
{
	if (par == 0)
	{
		p->txt.p=p->txt.pu;
		p->p.y -= 64;
		p->mv++;
	}
	else if (par == 1)
	{
		p->txt.p=p->txt.pd;
		p->p.y += 64;
		p->mv++;
	}
	else if (par == 2)
	{
		p->txt.p=p->txt.pl;
		p->p.x -= 64;
		p->mv++;
	}
	else if (par == 3)
	{
		p->txt.p=p->txt.pr;
		p->p.x += 64;
		p->mv++;
	}
	ft_putstr("Moves: ");
	ft_putnbr(p->mv);
	ft_putchar('\n');
}

void	draw_map(t_game g, t_map map, int i, int j)
{
	while (map.ln[++i])
	{
		j = -1;
		while (map.ln[i][++j])
		{
			if (map.ln[i][j] == '1')
				MLX_PUT(g.mlx, g.win, g.txt.w.img, j * 64, i * 64);
			else if (map.ln[i][j] == 'C')
			{
				MLX_PUT(g.mlx, g.win, g.txt.f.img, j * 64, i * 64);
				MLX_PUT(g.mlx, g.win, g.txt.c[0].img, j * 64, i * 64);
			}
			// else if (map.ln[i][j] == 'M')
			// {
			// 	MLX_PUT(g.mlx, g.win, g.txt.f.img, j * 64, i * 64);
			// 	MLX_PUT(g.mlx, g.win, g.txt.m.img, j * 64, i * 64);
			// }
			else
				MLX_PUT(g.mlx, g.win, g.txt.f.img, j * 64, i * 64);
		}
	}
	if (g.p.c_col == g.map.coins)
		MLX_PUT(g.mlx, g.win, g.txt.e_o.img, map.ex_x * 64, map.ex_y * 64);
	else
		MLX_PUT(g.mlx, g.win, g.txt.e_c.img, map.ex_x * 64, map.ex_y * 64);
	MLX_PUT(g.mlx, g.win, g.txt.p.img, g.p.x, g.p.y);
	MLX_PUT(g.mlx, g.win, g.txt.m.img, g.m.x, g.m.y);

	put_moves(g);
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
		&& p->p.x == p->map.ex_x * 64 && p->p.y == p->map.ex_y * 64)
		quit(p);
	if(p->p.x == p->m.x && p->p.y == p->m.y)
		quit(p);
	return (0);
}

int draw_enemy(t_game *g)
{
	m_enemy(g);
	draw_map(*g, g->map, -1, -1);
	return 0;
}

void	main_game(t_map map)
{
	t_game	game;

	game.map = map;
	game.p.x = map.pos_x * 64;
	game.p.y = map.pos_y * 64;
	game.m.x = map.m_x * 64;
	game.m.y = map.m_y * 64;
	game.p.c_col = 0;
	game.mv = 0;
	game.mlx = mlx_init();
	mlx_do_key_autorepeaton(game.mlx);
	game.win = mlx_new_window(game.mlx, map.x * 64, map.y * 64, "bunda");
	load_textures(&game.txt,game);

	mlx_key_hook(game.win, f, &game);
	mlx_loop_hook(game.mlx,draw_enemy,&game);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
