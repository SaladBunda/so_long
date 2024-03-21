/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:32 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/20 22:35:37 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_fds(char *path, int *c_fd, int *l_fd, int *count)
{
	*c_fd = open(path, O_RDONLY);
	*count = count_lines(*c_fd);
	*l_fd = open(path, O_RDONLY);
	free(path);
}

void	ft_settozero(int b[], int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		i++;
		(*(b++)) = c;
	}
	return ;
}

void	put_moves(t_game g)
{
	char	*str;

	str = n_moves(g.mv);
	MLX_S(g.mlx, g.win, (g.map.x - 2) * 64, 20, 0x00FF00, str);
	free(str);
	str = NULL;
}

void	output_enemy(t_game g)
{
	int	i;

	i = 0;
	while (i < g.m_num)
	{
		MLX_PUT(g.mlx, g.win, g.txt.m.img, (*g.m)[i].x, (*g.m)[i].y);
		i++;
	}
}

void	initiate_var(t_game *g, t_map map)
{
	int	i;

	i = 0;
	g->map = map;
	g->p.x = map.pos_x * 64;
	g->p.y = map.pos_y * 64;
	g->p.c_col = 0;
	g->mv = 0;
	g->timer1 = 0;
	g->timer2 = 0;
	g->seed = 12345;
	g->m_num = map.m_num;
	g->coin_index = 0;
	while (i < map.m_num)
	{
		(*g->m)[i].x = (*map.m)[i].x * 64;
		(*g->m)[i].y = (*map.m)[i].y * 64;
		i++;
	}
}
