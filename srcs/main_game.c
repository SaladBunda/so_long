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

void load_textures(t_txts *xmp,t_game game)
{
	xmp->wall.img = mlx_xpm_file_to_image(game.mlx,"./textures/Wall.xpm",&xmp->wall.width,&xmp->wall.height);
	xmp->wall.addr=mlx_get_data_addr(xmp->wall.img,&xmp->wall.bits_per_pixel, &xmp->wall.line_length, &xmp->wall.endian);
	xmp->floor.img = mlx_xpm_file_to_image(game.mlx,"./textures/floor.xpm",&xmp->floor.width,&xmp->floor.height);
	xmp->floor.addr=mlx_get_data_addr(xmp->floor.img,&xmp->floor.bits_per_pixel, &xmp->floor.line_length, &xmp->floor.endian);
	xmp->plyr.img=mlx_xpm_file_to_image(game.mlx,"./textures/player.xpm",&xmp->plyr.width,&xmp->plyr.height);
	xmp->plyr.addr=mlx_get_data_addr(xmp->plyr.img, &xmp->plyr.bits_per_pixel,&xmp->plyr.line_length,&xmp->plyr.endian);
	xmp->coins.img=mlx_xpm_file_to_image(game.mlx,"./textures/coin.xpm",&xmp->coins.width,&xmp->coins.height);
	xmp->coins.addr=mlx_get_data_addr(xmp->coins.img, &xmp->coins.bits_per_pixel,&xmp->coins.line_length,&xmp->coins.endian);
	xmp->exit_c.img=mlx_xpm_file_to_image(game.mlx,"./textures/exit_c.xpm",&xmp->exit_c.width,&xmp->exit_c.height);
	xmp->exit_c.addr=mlx_get_data_addr(xmp->exit_c.img, &xmp->exit_c.bits_per_pixel,&xmp->exit_c.line_length,&xmp->exit_c.endian);
	xmp->exit_o.img=mlx_xpm_file_to_image(game.mlx,"./textures/exit_o.xpm",&xmp->exit_o.width,&xmp->exit_o.height);
	xmp->exit_o.addr=mlx_get_data_addr(xmp->exit_o.img, &xmp->exit_o.bits_per_pixel,&xmp->exit_o.line_length,&xmp->exit_o.endian);
}

void draw_map(t_game game,t_map map)
{
	t_txts img;
	load_textures(&img,game);
	int i=0;
	int j;
	while(map.lines[i])
	{
		j=0;
		while(map.lines[i][j])
		{
			if(map.lines[i][j] == '1')
				mlx_put_image_to_window(game.mlx,game.win,img.wall.img,j*64,i*64);
			else if(map.lines[i][j] == 'C')
			{
				mlx_put_image_to_window(game.mlx,game.win,img.floor.img,j*64,i*64);
				mlx_put_image_to_window(game.mlx,game.win,img.coins.img,j*64,i*64);
			}
			else
				mlx_put_image_to_window(game.mlx,game.win,img.floor.img,j*64,i*64);
			j++;	
		}
		i++;
	}
	mlx_put_image_to_window(game.mlx,game.win,img.plyr.img,game.p.x,game.p.y);
	if(game.p.c_col==game.map.coins)
		mlx_put_image_to_window(game.mlx,game.win,img.exit_o.img,map.exit_x*64,map.exit_y*64);
	else
		mlx_put_image_to_window(game.mlx,game.win,img.exit_c.img,map.exit_x*64,map.exit_y*64);
}


int f(int key, t_game *param)
{
	if(key == UP_KEY && param->map.lines[(param->p.y-64)/64][param->p.x/64]!='1')
		param->p.y-=64;
	else if(key == DOWN_KEY  && param->map.lines[(param->p.y+64)/64][param->p.x/64]!='1')
		param->p.y+=64;
	else if(key == LEFT_KEY && param->map.lines[param->p.y/64][(param->p.x-64)/64]!='1')
		param->p.x-=64;
	else if (key == RIGHT_KEY && param->map.lines[param->p.y/64][(param->p.x+64)/64]!='1')
		param->p.x+=64;
	else if(key == ESC_KEY )
	{
		mlx_destroy_window(param->mlx,param->win);
		exit(1);
	}
	if(param->map.lines[param->p.y/64][param->p.x/64]=='C')
	{
		param->p.c_col++;
		param->map.lines[param->p.y/64][param->p.x/64]='0';
	}
	draw_map(*param,param->map);
	ft_put_u(param->map.exit_x);
	ft_put_u(param->map.exit_y);
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
	game.p.x=map.pos_x*64;
	game.p.y=map.pos_y*64;
	game.p.c_col=0;
    game.mlx=mlx_init() ;
	game.win=mlx_new_window(game.mlx,map.x * 64,map.y * 64,"bunda");
	mlx_key_hook(game.win, f, &game);
	if(i++ == 0)
		draw_map(game,map);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}


