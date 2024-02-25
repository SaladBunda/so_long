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

void draw_map(t_game game,t_map map)
{
	t_img wall;
	t_img floor;
	wall.img = mlx_xpm_file_to_image(game.mlx,"./textures/Wall.xpm",&wall.width,&wall.height);
	wall.addr=mlx_get_data_addr(wall.img,&wall.bits_per_pixel, &wall.line_length, &wall.endian);
	floor.img = mlx_xpm_file_to_image(game.mlx,"./textures/floor.xpm",&floor.width,&floor.height);
	floor.addr=mlx_get_data_addr(floor.img,&floor.bits_per_pixel, &floor.line_length, &floor.endian);
	// ft_putchar('1');
	t_img player;
	player.img=mlx_xpm_file_to_image(game.mlx,"./textures/player.xpm",&player.width,&player.height);
	player.addr=mlx_get_data_addr(player.img, &player.bits_per_pixel,&player.line_length,&player.endian);
	
	int i=0;
	int j;
	while(map.lines[i])
	{
		j=0;
		while(map.lines[i][j])
		{
			if(map.lines[i][j] == '1')
				mlx_put_image_to_window(game.mlx,game.win,wall.img,j*64,i*64);
			else
				mlx_put_image_to_window(game.mlx,game.win,floor.img,j*64,i*64);
			j++;	
		}
		i++;
	}
	mlx_put_image_to_window(game.mlx,game.win,player.img,game.p.x,game.p.y);
}

int f(int key, t_game *param)
{
	// ft_putchar(param->map.lines[param->p.x/64][param->p.y/64]);
	// ft_putchar
	ft_put_u((param->p.x)/64);
	ft_putchar(' ');
	ft_put_u((param->p.y)/64);
	ft_putchar('\n');

	if((key == UP_KEY || key == L_UP_KEY) && param->map.lines[(param->p.y-64)/64][param->p.x/64]!='1')
		param->p.y-=64;
	else if((key == DOWN_KEY || key == L_DOWN_KEY) && param->map.lines[(param->p.y+64)/64][param->p.x/64]!='1')
		param->p.y+=64;
	else if((key == LEFT_KEY || key == L_LEFT_KEY) && param->map.lines[param->p.y/64][(param->p.x-64)/64]!='1')
		param->p.x-=64;
	else if ((key == RIGHT_KEY|| key == L_RIGHT_KEY) && param->map.lines[param->p.y/64][(param->p.x+64)/64]!='1')
		param->p.x+=64;
	else if(key == ESC_KEY || key == L_ESC_KEY)
	{
		mlx_destroy_window(param->mlx,param->win);
		exit(1);
	}
	
	draw_map(*param,param->map);
	return 0;
}


int quit(t_game *param)
{

	mlx_destroy_window(param->mlx,param->win);
	exit(1);
}

void main_game(t_map map)
{
	t_game game;
	int i =0;
	game.map=map;
	game.p.x=game.map.pos_x*64;
	game.p.y=game.map.pos_y*64;
	game.p.c_col=0;
    game.mlx=mlx_init() ;
	game.win=mlx_new_window(game.mlx,map.x * 64,map.y * 64,"bunda");
	mlx_key_hook(game.win, f, &game);
	if(i++ == 0)
		draw_map(game,map);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}




/* void my_put_ps(t_img *data, int x, int y,int color)
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
} */


