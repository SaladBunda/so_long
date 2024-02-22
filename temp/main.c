/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:42:52 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/19 15:51:37 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct img_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} imgdata;

typedef struct mlx_data
{
	void *mlx_p;
	void *mlx_w;
} mlxdata;

void my_put_ps(imgdata *data, int x, int y,int color)
{
	char *dst;

	dst=data->addr + (y*data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void make_image(imgdata *data, int x, int y,int color)
{
	int i=0;
	int j=0;
	while(i < x)
	{
		j=0;
		while(j<y)
		{
			my_put_ps(data,i,j,color);
			// mlx_pixel_put()
			j++;
		}
		i++;
	}
}

int main()
{
	mlxdata ptr;
	ptr.mlx_p = mlx_init();// establishing connection to the graphical system (x window)
	ptr.mlx_w = mlx_new_window(ptr.mlx_p, 1000,1000 ,"bunda"); //creating a new window instance 
	imgdata img;
	img.img=mlx_new_image(ptr.mlx_p,100,100);
	img.addr=mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_image(&img,100,100,255);
	int x = 0;
	int y = 0;
	int times = 0;
	// while(times < 100)
	// {
	while(x < 1000)
	{
		y=0;
		while(y<1000)
		{
			mlx_put_image_to_window(ptr.mlx_p, ptr.mlx_w,img.img,x,y);
			y+=100;
		}
		x+=100;
	}
	make_image(&img,100,100,100);
	x = 100;
	y=100;
	while(x<900)
	{
		y=100;
		while(y<900)
		{
			mlx_put_image_to_window(ptr.mlx_p, ptr.mlx_w,img.img,x,y);
			y+=100;
		}
		x+=100;
	}
		
	// }
	// mlx_put_image_to_window(mlx_ptr, mlx_wdw,img.img,100,0);
	mlx_loop(ptr.mlx_p);

	
}