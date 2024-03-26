/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/26 19:50:09 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game game)
{
	int	i;

	i = 0;
	while (game.map.ln[i])
		free(game.map.ln[i++]);
	free(game.map.ln);
}

int	quit(t_game *p, int option)
{
	if (p->p.c_col == p->map.coins 
		&& p->p.x == p->map.ex_x * 64 && p->p.y == p->map.ex_y * 64)
		ft_putstr("You Won!!!!");
	if(option == 1)
		ft_putstr("Invalid Textures??\n");
	mlx_destroy_window(p->mlx, p->win);
	free_map(*p);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	get_fds(char *path, int *c_fd, int *l_fd, int *count)
{
	*c_fd = open(path, O_RDONLY);
	*count = count_lines(*c_fd);
	*l_fd = open(path, O_RDONLY);
	if((*c_fd) == -1 || (*l_fd) == -1)
		return (0);
	else
		return (1);
}

int	draw_enemy(t_game *g)
{
	draw_map(*g, g->map, -1, -1);
	return (0);
}
