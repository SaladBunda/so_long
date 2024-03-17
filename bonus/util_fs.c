/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:57:03 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/03/17 15:50:56 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(int fd)
{
	int	count;
	char *str;

	str = get_next_line(fd);
	count = 0;
	while (str)
	{
		free(str);
		str = NULL;
		str = get_next_line(fd);
		count++;
	}
	free(str);
	str = NULL;
	return (count);
}

char	*get_path(char *filename, int i)
{
	int		length;
	char	*tmp;
	char	*path;
	char	*fullpath;

	length = ft_strlen(filename);
	path = "./maps/";
	fullpath = malloc(length + ft_strlen(path) + 1);
	if (!fullpath)
		return (NULL);
	while (i < ft_strlen(path) + length + 1)
		fullpath[i++] = 0;
	ft_strncat(fullpath, path, ft_strlen(path));
	ft_strncat(fullpath, filename, length);
	tmp = fullpath;
	// free(fullpath);
	return (tmp);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1); 
}

void	ft_putnbr(int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
