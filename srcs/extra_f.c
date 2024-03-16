/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/16 13:35:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game game)
{
	int	i;
	i = 0;

	while(game.map.ln[i])
		free(game.map.ln[i++]);
	free(game.map.ln);
}

int	quit(t_game *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_map(*param);
	exit(1);
}
void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		write(1,&str[i++],1);
}