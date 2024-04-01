/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/30 20:12:32 by ael-maaz         ###   ########.fr       */
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
	if (option == 1)
		ft_putstr("Invalid Textures??\n");
	if (option == 2)
		ft_putstr("You exited the game\n");
	if (option == 3)
	{
		write(2, "Error while starting game\n", 26);
		free_map(*p);
		exit (1);
	}
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

int	get_fds(t_map *map, int *c_fd, int *l_fd, int *count)
{
	*c_fd = open(map->fullpath, O_RDONLY);
	*l_fd = open(map->fullpath, O_RDONLY);
	*count = count_lines(*c_fd);
	close(*c_fd);
	free(map->fullpath);
	if (*count >= 129)
		return (13);
	if ((*c_fd) == -1 && (*l_fd) == -1)
		return (6);
	else
		return (0);
}

int	draw_enemy(t_game *g)
{
	draw_map(*g, g->map, -1, -1);
	return (0);
}
