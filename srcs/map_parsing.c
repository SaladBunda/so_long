/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:33 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/22 22:27:11 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void start_position(char *map[],int *x, int *y)
{
	int i =1;
	int j;
	while(map[i+1])
	{
		j=1;
		while(map[i][j+1])
		{
			if(map[i][j]=='P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void flood_fill(char *grid[], int start_x, int start_y, int height, int width)
{
    if (start_x < 0 || start_x >= height || start_y < 0 || start_y >= width)
        return;
    
    if (grid[start_x][start_y] == '1')
        return;
    
    grid[start_x][start_y] = '1';

    flood_fill(grid, start_x + 1, start_y, height, width); // Down
    flood_fill(grid, start_x - 1, start_y, height, width); // Up
    flood_fill(grid, start_x, start_y + 1, height, width); // Right
    flood_fill(grid, start_x, start_y - 1, height, width); // Left
}

int checking_filled_map(char *map[],int width,int height)
{
	int i=0;
	int j;
	while(i<height)
	{
		j=0;
		while(j<width)
		{
			if(map[i][j]!='0'&& map[i][j]!='1')
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int parsing_test(char *map[], int width, int height)
{
	int x;
	int y;
	start_position(map,&x,&y);
	flood_fill(map,y,x,height,width);
	int i=0;
	while(map[i])
		printf("%s\n",map[i++]);
	if(checking_filled_map(map,width,height)==1)
		return 1;
	return 0;
}
