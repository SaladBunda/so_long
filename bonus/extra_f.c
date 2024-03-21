/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/20 22:04:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int n)
{
	int		cpy;
	int		count;
	char	*s;

	count = 0;
	if (n == 0)
		count++;
	cpy = n;
	while (cpy > 0)
	{
		count++;
		cpy /= 10;
	}
	s = malloc((count + 1) * sizeof(char));
	s[count] = 0;
	while (count > 0)
	{
		s[--count] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

char	*n_moves(int n)
{
	int		length;
	int		i;
	char	*path;
	char	*fullpath;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	length = ft_strlen(str);
	path = "Moves:";
	fullpath = malloc(length + ft_strlen(path) + 1);
	if (!fullpath)
		return (NULL);
	while (i < ft_strlen(path) + length + 1)
		fullpath[i++] = 0;
	ft_strncat(fullpath, path, ft_strlen(path));
	ft_strncat(fullpath, str, length);
	free(str);
	str = NULL;
	return (fullpath);
}

void	free_map(t_game game)
{
	int	i;

	i = 0;
	while (game.map.ln[i])
		free(game.map.ln[i++]);
	free(game.map.ln);
}

int	quit(t_game *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_map(*param);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
