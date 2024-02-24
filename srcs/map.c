/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:50:28 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/24 21:25:18 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ext_test(char *filename)
{
	int i=0;
	while(filename[i])
		i++;
	i--;
	if(filename[i] == 'r')
	{
		i--;
		if(filename[i] == 'e')
		{
			i--;
			if(filename[i] == 'b')
			{
				i--;
				if(filename[i] == '.')
					return (1);
			}
		}
	}
	return 0;
}

int test_lines(char *lines[])
{
	int i=0;
	int line_len=ft_strlen(lines[i]);
	while(lines[i])
	{
		if(line_len != ft_strlen(lines[i]))
			return 0;
		else
			i++;
	}
	return 1;
}

int test_borders(char *map[],int width,int height)
{
	int i=0;
	int j = 0;
	while(i< height)
	{
		j=0;
		while(j<width)
		{
			if (j>0 && j<width-1 && i>0 && i<height-1)
				j++;
			else
			{
				if(map[i][j]=='1')
					j++;
				else
					return 0;
			}
		}
		i++;
	}
	return 1;
}

int test_pixels(int array[],int width , int height)
{
	int contour=4+(width-2)*2+(height-2)*2;
	if(array[3]!=1)
		return 0;
	if(array[4]!=1)
		return 0;
	if(array[1]<contour)
		return 0;
	if(array[2]<1)
		return 0;
	return 1;
}

int fill_pixels(t_map *map)
{
	int i = 0;
	int j;
	int arr[5]={0,0,0,0,0};
	while(map->lines[i])
	{
		j=0;
		while(map->lines[i][j])
		{
			if(map->lines[i][j]=='0')
				arr[0]++;
			else if(map->lines[i][j]=='1')
				arr[1]++;
			else if(map->lines[i][j]=='C')
				arr[2]++;
			else if(map->lines[i][j]=='E')
				arr[3]++;	
			else if(map->lines[i][j]=='P')
				arr[4]++;	
			else
				return 0;
			j++;
		}
		i++;
	}
	return (map->coins=arr[2],test_pixels(arr,map->x,map->y));
}


int map_tests(char *filename, t_map *map)
{
	int count ;
	int count_fd = open(get_path(filename), O_RDONLY);
	count = count_lines(count_fd);
	if (count <= 2)
		return 0;
	int lines_fd = open(get_path(filename), O_RDONLY);
	map->lines=malloc((count +1)*sizeof(char *));
	if (!map->lines)
		return 0;
	int i=0;
	while(i < count)
		map->lines[i++]=get_next_line(lines_fd);
	map->lines[i]=NULL;
	if(test_lines(map->lines)!=1)
		return 0;
	map->y=count;
	map->x=ft_strlen(map->lines[0]);
	if(fill_pixels(map)!=1)
			return 0;
	if(test_borders(map->lines,map->x,map->y)!=1)
			return 0;
	if(parsing_test(map))
			return(1);
	return 0;
}

