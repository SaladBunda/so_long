/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:06:44 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/19 02:47:10 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296 

int lcg_rand() {
	static unsigned int lcg_seed = 12345; 
    lcg_seed = (LCG_A * lcg_seed + LCG_C) % LCG_M;
    return (lcg_seed % 40);
}

int get_direction()
{
	int direction;
	int random;
	
	random = lcg_rand();
	direction = 0;
	if(random>=0 && random<=10)
		direction = 0;
	else if(random>=11 && random<=20)
		direction = 1;
	else if(random>=21 && random<=30)
		direction = 2;
	else if(random>=31 && random<=40)
		direction = 3;
	return (direction);
}

void move_in_map(t_game *g, int par)
{
	if (par == 0)
		g->m.y -= 64;
	else if (par == 1)
		g->m.y += 64;
	else if (par == 2)
		g->m.x -= 64;
	else if (par == 3)
		g->m.x += 64;
}

void m_enemy(t_game *g)
{
	int direction;
	direction = get_direction();
	static int i = 0;
	if(i > 35)
	{
		if (direction == 0 && g->map.ln[(g->m.y - 64) / 64][g->m.x / 64] != '1')
			move_in_map(g, 0);
		else if (direction == 1 && g->map.ln[(g->m.y + 64) / 64][g->m.x / 64] != '1')
			move_in_map(g, 1);
		else if (direction == 2 && g->map.ln[g->m.y / 64][(g->m.x - 64) / 64] != '1')
			move_in_map(g, 2);
		else if (direction == 3 && g->map.ln[g->m.y / 64][(g->m.x + 64) / 64] != '1')
			move_in_map(g, 3);
		i = 0;	
	}
	else
		i++;
	if(g->m.x == g->p.x && g->m.y == g->p.y)
		quit(g);
}

int draw_enemy(t_game *g)
{
	m_enemy(g);
	draw_map(*g, g->map, -1, -1);
	return 0;
}