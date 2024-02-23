/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:49:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 01:49:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key_codes.h"

void ft_putchar(int c)
{
	write(1,&c,1);
}

static void	recurs(long n, int *index)
{
	(*index)++;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		recurs(n / 10, index);
		ft_putchar((n % 10) + '0');
	}
}

int	ft_put_u(unsigned int n)
{
	int	i;

	i = 0;
	recurs(n, &i);
	return (i);
}


int f(int key, t_game *param)
{
	static int color=255;
	static int x=100;
	static int y=100;
	ft_put_u(key);
	if(key == UP_KEY)
		y-=10;
	else if(key == DOWN_KEY)
		y+=10;
	else if(key == LEFT_KEY)
		x-=10;
	else if (key == RIGHT_KEY)
		x+=10;
	else if(key == ESC_KEY)
	{
		mlx_destroy_window(param->)
	}
	
	mlx_pixel_put(param->mlx,param->win,x,y,color);


	color+=0x0000FF;
	return 0;
}

void main_game(t_map map)
{
	t_game game;
    game.mlx=mlx_init() ;
	game.win=mlx_new_window(game.mlx,map.x * 100,map.y * 100,"bunda");
	mlx_key_hook(game.win, f, &game);
	// ft_put_u(i);
	mlx_loop(game.mlx);

}