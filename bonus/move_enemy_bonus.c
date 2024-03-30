/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:06:44 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/30 19:41:58 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296 

int	lcg_rand(unsigned int *seed)
{
	*seed = (LCG_A * (*seed) + LCG_C) % LCG_M;
	return (*seed % 40);
}

int	get_direction(unsigned int *seed)
{
	int	direction;
	int	random;

	random = lcg_rand(seed);
	direction = 0;
	if (random >= 0 && random <= 10)
		direction = 0;
	else if (random >= 11 && random <= 20)
		direction = 1;
	else if (random >= 21 && random <= 30)
		direction = 2;
	else if (random >= 31 && random <= 40)
		direction = 3;
	return (direction);
}

void	move_in_map(t_game *g, int par, int i)
{
	if (par == 0)
		(*g->m)[i].y -= 64;
	else if (par == 1)
		(*g->m)[i].y += 64;
	else if (par == 2)
		(*g->m)[i].x -= 64;
	else if (par == 3)
		(*g->m)[i].x += 64;
}

void	m_enemy(t_game *g, int i)
{
	int	dir;

	dir = get_direction(&(g->seed));
	if (dir == 0 && g->map.ln[((*g->m)[i].y - 64) / 64][(*g->m)[i].x / 64]
		!= '1')
		move_in_map(g, 0, i);
	else if (dir == 1 && g->map.ln[((*g->m)[i].y + 64) / 64][(*g->m)[i].x / 64] 
	!= '1')
		move_in_map(g, 1, i);
	else if (dir == 2 && g->map.ln[(*g->m)[i].y / 64][((*g->m)[i].x - 64) / 64] 
	!= '1')
		move_in_map(g, 2, i);
	else if (dir == 3 && g->map.ln[(*g->m)[i].y / 64][((*g->m)[i].x + 64) / 64] 
	!= '1')
		move_in_map(g, 3, i);
	if ((*g->m)[i].x == g->p.x && (*g->m)[i].y == g->p.y)
	{
		ft_putstr("You Lost!");
		quit(g, 0);
	}
}

int	draw_enemy(t_game *g)
{
	int	i;

	if (g->timer1 > 35)
	{
		i = 0;
		while (i < g->m_num)
			m_enemy(g, i++);
		g->timer1 = 0;
	}
	else
		g->timer1++;
	if (g->timer2 > 5)
	{
		g->txt.co = g->txt.c[g->coin_index++ % 12];
		g->timer2 = 0;
	}
	else
		g->timer2++;
	draw_map(*g, g->map, -1, -1);
	return (0);
}
