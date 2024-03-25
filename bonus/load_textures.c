/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:27:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/22 21:03:31 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player(t_txts *x, t_game g)
{
	x->pu.img = MLX_X(g.mlx, "./textures/pu.xpm", &x->pu.wth, &x->pu.hht);
	if(!(x->pu.img))
			quit(&g, 1);
	x->pd.img = MLX_X(g.mlx, "./textures/pd.xpm", &x->pd.wth, &x->pd.hht);
	if(!(x->pd.img))
			quit(&g, 1);
	x->pr.img = MLX_X(g.mlx, "./textures/pr.xpm", &x->pr.wth, &x->pr.hht);
	if(!(x->pr.img))
			quit(&g, 1);
	x->pl.img = MLX_X(g.mlx, "./textures/pl.xpm", &x->pl.wth, &x->pl.hht);
	if(!(x->pl.img))
			quit(&g, 1);
	x->pu.a = MLX_D(x->pu.img, &x->pu.bpp, &x->pu.ll, &x->pu.en);
	x->pd.a = MLX_D(x->pd.img, &x->pd.bpp, &x->pd.ll, &x->pd.en);
	x->pr.a = MLX_D(x->pr.img, &x->pr.bpp, &x->pr.ll, &x->pr.en);
	x->pl.a = MLX_D(x->pl.img, &x->pl.bpp, &x->pl.ll, &x->pl.en);
	x->p = x->pu;
}

char	*get_texture_path(int i, int j)
{
	char	*number;
	char	*path;
	char	*fullpath;
	char	*ext;

	number = ft_itoa(j);
	path = "./textures/c";
	ext = ".xpm";
	fullpath = malloc(ft_strlen("./textures/c") + ft_strlen(ext) + 2);
	if (!fullpath)
		return (NULL);
	while (i < ft_strlen("./textures/c") + ft_strlen(ext) + 2)
		fullpath[i++] = 0;
	ft_strncat(fullpath, path, ft_strlen(path));
	ft_strncat(fullpath, number, ft_strlen(number));
	ft_strncat(fullpath, ext, ft_strlen(ext));
	free(number);
	return (fullpath);
}

void	load_coins(t_txts *x, t_game g)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 12)
	{
		path = get_texture_path(0, i + 1);
		x->c[i].img = MLX_X(g.mlx, path, &x->c[i].wth, &x->c[i].hht);
		if(!(x->c[i].img))
			quit(&g, 1);
		x->c[i].a = MLX_D(x->c[i].img, &x->c[i].bpp, &x->c[i].ll, &x->c[i].en);
		free(path);
		path = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

void	load_textures(t_txts *x, t_game g)
{
	x->w.img = MLX_X(g.mlx, "./textures/W.xpm", &x->w.wth, &x->w.hht);
	if(!(x->w.img))
			quit(&g, 1);
	x->f.img = MLX_X(g.mlx, "./textures/f.xpm", &x->f.wth, &x->f.hht);
	if(!(x->f.img))
			quit(&g, 1);
	x->m.img = MLX_X(g.mlx, "./textures/M.xpm", &x->m.wth, &x->m.hht);
	if(!(x->m.img))
			quit(&g, 1);
	x->e_c.img = MLX_X(g.mlx, "./textures/ec.xpm", &x->e_c.wth, &x->e_c.hht);
	if(!(x->e_c.img))
			quit(&g, 1);
	x->e_o.img = MLX_X(g.mlx, "./textures/eo.xpm", &x->e_o.wth, &x->e_o.hht);
	if(!(x->e_o.img))
			quit(&g, 1);
	x->w.a = MLX_D(x->w.img, &x->w.bpp, &x->w.ll, &x->w.en);
	x->f.a = MLX_D(x->f.img, &x->f.bpp, &x->f.ll, &x->f.en);
	x->m.a = MLX_D(x->m.img, &x->m.bpp, &x->m.ll, &x->m.en);
	x->e_c.a = MLX_D(x->e_c.img, &x->e_c.bpp, &x->e_c.ll, &x->e_c.en);
	x->e_o.a = MLX_D(x->e_o.img, &x->e_o.bpp, &x->e_o.ll, &x->e_o.en);
	load_coins(x, g);
	load_player(x, g);
}

