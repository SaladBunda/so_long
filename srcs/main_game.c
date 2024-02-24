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
		mlx_destroy_window(param->mlx,param->win);
	}
	
	mlx_pixel_put(param->mlx,param->win,x,y,color);


	color+=0x0000FF;
	return 0;
}

void my_put_ps(t_img *data, int x, int y,int color)
{
	char *dst;

	dst=data->addr + (y*data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void make_image(t_img *data, int x, int y,int color)
{
	int i=0;
	int j=0;
	while(i < x)
	{
		j=0;
		while(j<y)
		{
			my_put_ps(data,i,j,color);
			j++;
		}
		i++;
	}
}

void draw_map(t_game game,t_map map)
{
	t_img wall;
	t_img floor;
	(void) map;
	wall.img=mlx_new_image(game.mlx,100,100);
	wall.addr=mlx_get_data_addr(wall.img,&wall.bits_per_pixel, &wall.line_length, &wall.endian);
	floor.img=mlx_new_image(game.mlx,100,100);
	floor.addr=mlx_get_data_addr(floor.img,&floor.bits_per_pixel, &floor.line_length, &floor.endian);

	int i=0;
	int j;
	make_image(&wall,100,100,0x000060);
	make_image(&floor,100,100,0x00FF00);
	while(map.lines[i])
	{
		j=0;
		while(map.lines[i][j])
		{
			if(map.lines[i][j] == '1')
				mlx_put_image_to_window(game.mlx,game.win,wall.img,j*100,i*100);
			else
				mlx_put_image_to_window(game.mlx,game.win,floor.img,j*100,i*100);
			j++;	

			mlx_pixel_put(game.mlx,game.win,j*100,i*100,0xFF0000);
		}
		i++;
	}
	// mlx_put_image_to_window(game.mlx,game.win,wall.img,x,y);
	// mlx_put_image_to_window(game.mlx,game.win,floor.img,x+100,y+100);

}

void main_game(t_map map)
{
	t_game game;
    game.mlx=mlx_init() ;
	game.win=mlx_new_window(game.mlx,map.x * 100,map.y * 100,"bunda");

	// mlx_key_hook(game.win, f, &game);
	draw_map(game,map);
	
	// ft_put_u(i);
	mlx_loop(game.mlx);

}