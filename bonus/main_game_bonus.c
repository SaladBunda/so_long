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

void	somethng(t_game *p, int par)
{
	if (par == 0)
	{
		p->txt.p = p->txt.pu;
		p->p.y -= 64;
		p->mv++;
	}
	else if (par == 1)
	{
		p->txt.p = p->txt.pd;
		p->p.y += 64;
		p->mv++;
	}
	else if (par == 2)
	{
		p->txt.p = p->txt.pl;
		p->p.x -= 64;
		p->mv++;
	}
	else if (par == 3)
	{
		p->txt.p = p->txt.pr;
		p->p.x += 64;
		p->mv++;
	}
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
				MLX_PUT(g.mlx, g.win, g.txt.co.img, j * 64, i * 64);
			}
			else
				MLX_PUT(g.mlx, g.win, g.txt.f.img, j * 64, i * 64);
		}
	}
	if (g.p.c_col == g.map.coins)
		MLX_PUT(g.mlx, g.win, g.txt.e_o.img, map.ex_x * 64, map.ex_y * 64);
	else
		MLX_PUT(g.mlx, g.win, g.txt.e_c.img, map.ex_x * 64, map.ex_y * 64);
	MLX_PUT(g.mlx, g.win, g.txt.p.img, g.p.x, g.p.y);
	output_enemy(g);
	put_moves(g);
}

void	check_collision(t_game *p)
{
	int	i;

	i = 0;
	while (i < p->m_num)
	{
		if (p->p.x == (*p->m)[i].x && p->p.y == (*p->m)[i].y)
		{
			ft_putstr("You Lost!");
			quit(p, 0);
		}
		i++;
	}
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
		quit(p, 2);
	if (p->map.ln[p->p.y / 64][p->p.x / 64] == 'C')
	{
		p->p.c_col++;
		p->map.ln[p->p.y / 64][p->p.x / 64] = '0';
	}
	if (p->p.c_col == p->map.coins 
		&& p->p.x == p->map.ex_x * 64 && p->p.y == p->map.ex_y * 64)
		quit(p, 0);
	check_collision(p);
	return (0);
}

void	main_game(t_map map)
{
	t_game		game;
	t_player	*arr;

	arr = malloc(sizeof(t_player) * map.m_num);
	if (!arr)
		return ;
	game.m = &arr;
	initiate_var(&game, map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.x * 64, map.y * 64, "bunda");
	load_textures(&game.txt, game);
	game.txt.co.img = game.txt.c[0].img;
	mlx_key_hook(game.win, f, &game);
	mlx_loop_hook(game.mlx, draw_enemy, &game);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
