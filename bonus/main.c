/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:47:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/04 13:27:45 by ael-maaz         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map	map;

	if (ac > 2 || ac == 1)
	{
		write(2, "incorrect arg", 14);
		return (0);
	}
	else
	{
		if (ext_test(av[1]) == 1)
		{
			perror("its a map\n");
			if (map_tests(av[1], &map, 0, 0) == 1)
			{
				main_game(map);
			}
			else
				perror("bad map");
		}
		else
			perror("not a .ber file");
	}
}
