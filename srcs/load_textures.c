/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:27:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/19 19:37:04 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	x->p = x->pu;
}

void	load_textures(t_txts *x, t_game g)
{
	x->w.img = MLX_XPM(g.mlx, "./textures/W.xpm", &x->w.wth, &x->w.hht);
	x->w.addr = MLX_DATA(x->w.img, &x->w.bpp, &x->w.ll, &x->w.en);
	x->f.img = MLX_XPM(g.mlx, "./textures/f.xpm", &x->f.wth, &x->f.hht);
	x->f.addr = MLX_DATA(x->f.img, &x->f.bpp, &x->f.ll, &x->f.en);
	x->c.img = MLX_XPM(g.mlx, "./textures/c.xpm", &x->c.wth, &x->c.hht);
	x->c.addr = MLX_DATA(x->c.img, &x->c.bpp, &x->c.ll, &x->c.en);
	x->e_c.img = MLX_XPM(g.mlx, "./textures/ec.xpm", &x->e_c.wth, &x->e_c.hht);
	x->e_c.addr = MLX_DATA(x->e_c.img, &x->e_c.bpp, &x->e_c.ll, &x->e_c.en);
	x->e_o.img = MLX_XPM(g.mlx, "./textures/eo.xpm", &x->e_o.wth, &x->e_o.hht);
	x->e_o.addr = MLX_DATA(x->e_o.img, &x->e_o.bpp, &x->e_o.ll, &x->e_o.en);
	load_player(x, g);
}

void	print_moves(t_game *p)
{
	ft_putstr("Moves: ");
	ft_putnbr(p->mv);
	ft_putchar('\n');
}
