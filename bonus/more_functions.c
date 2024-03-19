/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:32 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/19 02:43:44 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void get_fds(char *path,int *c_fd, int *l_fd, int *count)
{
	*c_fd = open(path, O_RDONLY);
	*count = count_lines(*c_fd);
	*l_fd = open(path, O_RDONLY);
}

void    ft_settozero(int b[], int c, int len)
{
    int    i;

    i = 0;
    while (i < len)
    {
        i++;
        (*(b++)) =  c;
    }
    return ;
}

void put_moves(t_game g)
{
	char *str;

	str = n_moves(g.mv);
	MLX_S(g.mlx, g.win, (g.map.x - 2) * 64, 20, 0x00FF00, n_moves(g.mv));
	free(str);
}