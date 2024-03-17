/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:47:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/17 15:50:44 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			ft_putstr("its a map\n");
			if (map_tests(av[1], &map, 0, 0) == 1)
			{
				main_game(map);
			}
			else
				ft_putstr("bad map");
		}
		else
			ft_putstr("not a .ber file");
	}
}
