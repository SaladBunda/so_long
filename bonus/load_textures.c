/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:27:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/19 20:28:04 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player(t_txts *x, t_game g)
{
	x->pu.img = MLX_X(g.mlx, "./textures/pu.xpm", &x->pu.wth, &x->pu.hht);
	x->pu.addr = MLX_D(x->pu.img, &x->pu.bpp, &x->pu.ll, &x->pu.en);
	x->pd.img = MLX_X(g.mlx, "./textures/pd.xpm", &x->pd.wth, &x->pd.hht);
	x->pd.addr = MLX_D(x->pd.img, &x->pd.bpp, &x->pd.ll, &x->pd.en);
	x->pr.img = MLX_X(g.mlx, "./textures/pr.xpm", &x->pr.wth, &x->pr.hht);
	x->pr.addr = MLX_D(x->pr.img, &x->pr.bpp, &x->pr.ll, &x->pr.en);
	x->pl.img = MLX_X(g.mlx, "./textures/pl.xpm", &x->pl.wth, &x->pl.hht);
	x->pl.addr = MLX_D(x->pl.img, &x->pl.bpp, &x->pl.ll, &x->pl.en);
	x->p = x->pu;
}

void	load_textures(t_txts *x, t_game g)
{
	x->w.img = MLX_X(g.mlx, "./textures/W.xpm", &x->w.wth, &x->w.hht);
	x->w.addr = MLX_D(x->w.img, &x->w.bpp, &x->w.ll, &x->w.en);
	x->f.img = MLX_X(g.mlx, "./textures/f.xpm", &x->f.wth, &x->f.hht);
	x->f.addr = MLX_D(x->f.img, &x->f.bpp, &x->f.ll, &x->f.en);
	x->c[0].img = MLX_X(g.mlx, "./textures/c.xpm", &x->c[0].wth, &x->c[0].hht);
	x->c[0].addr = MLX_D(x->c[0].img, &x->c[0].bpp, &x->c[0].ll, &x->c[0].en);
	x->m.img = MLX_X(g.mlx, "./textures/M.xpm", &x->m.wth, &x->m.hht);
	x->m.addr = MLX_D(x->m.img, &x->m.bpp, &x->m.ll, &x->m.en);
	x->e_c.img = MLX_X(g.mlx, "./textures/ec.xpm", &x->e_c.wth, &x->e_c.hht);
	x->e_c.addr = MLX_D(x->e_c.img, &x->e_c.bpp, &x->e_c.ll, &x->e_c.en);
	x->e_o.img = MLX_X(g.mlx, "./textures/eo.xpm", &x->e_o.wth, &x->e_o.hht);
	x->e_o.addr = MLX_D(x->e_o.img, &x->e_o.bpp, &x->e_o.ll, &x->e_o.en);
	load_player(x, g);
}

void	print_moves(t_game *p)
{
	ft_putstr("Moves: ");
	ft_putnbr(p->mv);
	ft_putchar('\n');
}
