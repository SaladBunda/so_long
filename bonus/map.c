/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:50:28 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/25 23:00:07 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	test_lines(char *lines[], t_map *map, int count)
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
	map->y = count;
	map->x = ft_strlen(map->ln[0]);
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
			if (j > 0 && j < width - 1 && i > 0 && i < height - 1)
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

int	test_pxl(int array[], int width, int height)
{
	int	contour;

	contour = 4 + (width - 2) * 2 + (height - 2) * 2;
	if (array[3] != 1)
		return (0);
	if (array[4] != 1)
		return (0);
	if (array[1] < contour)
		return (0);
	if (array[2] < 1)
		return (0);
	if (array[5] < 1)
		return (0);
	return (1);
}

int	fill_pixels(t_map *map, int i, int j)
{
	int	a[6];

	ft_settozero(a, 0, 6);
	while (map->ln[++i])
	{
		j = -1;
		while (map->ln[i][++j])
		{
			if (map->ln[i][j] == '0')
				a[0]++;
			else if (map->ln[i][j] == '1')
				a[1]++;
			else if (map->ln[i][j] == 'C')
				a[2]++;
			else if (map->ln[i][j] == 'E')
				a[3]++;
			else if (map->ln[i][j] == 'P')
				a[4]++;
			else if (map->ln[i][j] == 'M')
				a[5]++;
			else
				return (0);
		}
	}
	return (map->coins = a[2], map->m_num = a[5], test_pxl(a, map->x, map->y));
}

int	map_tests(char *filename, t_map *map, int count_fd, int lines_fd)
{
	int			count;
	int			i;
	char		*path;
	t_player	*enemy;

	path = get_path(filename, 0);
	i = get_fds(path, &count_fd, &lines_fd, &count);
	map->ln = malloc((count + 1) * sizeof(char *));
	if (!map->ln)
		return (0);
	while (i <= count)
		map->ln[i++] = get_next_line(lines_fd);
	if (test_lines(map->ln, map, count) != 1)
		return (0);
	if (fill_pixels(map, -1, -1) != 1)
		return (0);
	enemy = malloc(sizeof(t_player) * map->m_num);
	if (!enemy)
		return (0);
	map->m = &enemy;
	if (test_borders(map->ln, map->x, map->y) != 1)
		return (0);
	if (parsing_test(map))
		return (1);
	return (0);
}
