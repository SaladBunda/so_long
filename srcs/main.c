/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:47:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/30 20:09:55 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ext_test(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i--;
	if (filename[i] == 'r')
	{
		i--;
		if (filename[i] == 'e')
		{
			i--;
			if (filename[i] == 'b')
			{
				i--;
				if (filename[i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

void	freeing_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->ln[i]);
		map->ln[i++] = NULL;
	}
	free(map->ln);
	map->ln = NULL;
}

void	print_errors(int param, t_map *map)
{
	if (param != 6)
	{
		if (param == 2)
			write(2, "Map must be a rectangle\n", 24);
		else if (param == 3)
		{
			if (fill_pixels(map, -1, -1) == 0)
				write(2, "Invalid characters in map\n", 26);
			else if (fill_pixels(map, -1, -1) == 10)
				write(2, "Invalid number of Player/Exit positions\n", 39);
			else if (fill_pixels(map, -1, -1) == 11)
				write(2, "The map must contain at least 1 coin\n", 37);
		}
		else if (param == 4)
			write(2, "Invalid borders\n", 16);
		else if (param == 5)
			write(2, "Invalid path\n", 13);
		else if (param == 0)
			write(2, "Error while creating game\n", 26);
		freeing_map(map);
		return ;
	}
	write(2, "Failed to open map file\n", 24);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		result;

	if (ac == 2)
	{
		ft_putstr("Testing map...\n");
		if (ext_test(av[1]) == 1)
		{
			result = map_tests(av[1], &map, 0, 0);
			if (result == 1)
			{
				ft_putstr("Valid map, starting game now...\nHAVE FUN!!\n");
				main_game(map);
			}
			else if (result == 13)
				write(2, "Map height/width shouldnt surpass 128 blocks\n", 49);
			else
				print_errors(result, &map);
		}
		else
			write(2, "not a .ber file\n", 16);
	}
	else
		write(2, "Usage: ./so_long (map name).ber\n", 32);
}
