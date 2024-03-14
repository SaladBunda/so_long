/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:33 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/13 20:26:00 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->ln[i + 1])
	{
		j = 1;
		while (map->ln[i][j + 1])
		{
			if (map->ln[i][j] == 'P')
			{
				map->pos_x = j;
				map->pos_y = i;
			}
			else if (map->ln[i][j] == 'E')
			{
				map->ex_x = j;
				map->ex_y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char *grid[], int x, int y, t_map map)
{
	if (x < 0 || x >= map.y || y < 0 || y >= map.x)
		return ;
	if (grid[x][y] == '1')
		return ;
	grid[x][y] = '1';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
}

int	checking_filled_map(char *map[], int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**clone_map(char *map[], t_map mapp)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = malloc((mapp.y + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < mapp.y)
		arr[i++] = malloc((mapp.x + 1) * sizeof(char));
	arr[i] = NULL;
	i = 0;
	while (i < mapp.y)
	{
		j = -1;
		while (++j < mapp.x)
			arr[i][j] = map[i][j];
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

int	parsing_test(t_map *map)
{
	int		i;
	char	**map_cpy;

	i = 0;
	start_position(map);
	map_cpy = clone_map(map->ln,*map);
	flood_fill(map_cpy, map->pos_y, map->pos_x, *map);
	i = 0;
	if (checking_filled_map(map_cpy, map->x, map->y) == 1)
	{
		while (i < map->y)
			free(map_cpy[i++]);
		free(map_cpy);
		return (1);
	}
	while (i < map->y)
		free(map_cpy[i++]);
	free(map_cpy);
	return (0);
}
