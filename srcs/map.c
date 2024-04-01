/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:50:28 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/30 19:48:31 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_lines(char *lines[])
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(lines[i]);
	while (lines[i])
	{
		if (line_len != ft_strlen(lines[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

int	test_borders(char *map[], int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = 0;
		while (j < width)
		{
			if (j > 0 && j < (width - 1) && i > 0 && i < (height - 1))
				j++;
			else
			{
				if (map[i][j] == '1')
					j++;
				else
					return (0);
			}
		}
	}
	return (1);
}

int	test_pixels(int array[], int width, int height)
{
	(void) width;
	(void) height;
	if (array[3] != 1 || array[4] != 1)
		return (10);
	if (array[2] < 1)
		return (11);
	return (1);
}

int	fill_pixels(t_map *map, int i, int j)
{
	int	arr[5];

	while (++j < 5)
		arr[j] = 0;
	while (map->ln[++i])
	{
		j = -1;
		while (map->ln[i][++j])
		{
			if (map->ln[i][j] == '0')
				arr[0]++;
			else if (map->ln[i][j] == '1')
				arr[1]++;
			else if (map->ln[i][j] == 'C')
				arr[2]++;
			else if (map->ln[i][j] == 'E')
				arr[3]++;
			else if (map->ln[i][j] == 'P')
				arr[4]++;
			else
				return (0);
		}
	}
	return (map->coins = arr[2], test_pixels(arr, map->x, map->y));
}

int	map_tests(char *filename, t_map *map, int count_fd, int lines_fd)
{
	int		count;
	int		i;

	map->fullpath = get_path(filename, 0);
	i = get_fds(map, &count_fd, &lines_fd, &count);
	if (i != 0)
		return (i);
	map->ln = malloc((count + 1) * sizeof(char *));
	if (!map->ln)
		return (0);
	while (i <= count)
		map->ln[i++] = get_next_line(lines_fd);
	map->y = count;
	map->x = ft_strlen(map->ln[0]);
	if (test_lines(map->ln) != 1)
		return (2);
	if (map->x >= 129)
		return (13);
	if (fill_pixels(map, -1, -1) != 1)
		return (3);
	if (test_borders(map->ln, map->x, map->y) != 1)
		return (4);
	if (parsing_test(map))
		return (1);
	return (5);
}
