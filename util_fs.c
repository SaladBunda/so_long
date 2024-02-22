/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:57:03 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/20 20:03:40 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(int fd)
{
	int count=0;
	while(get_next_line(fd))
		count++;
	return count;
}

char *get_path(char *filename)
{
	int length = 0;
	int i = 0;
	length = ft_strlen(filename);
	char *path="./maps/";
	char *fullpath=malloc(length + ft_strlen(path) + 1);
	if (!fullpath)
		return NULL;
	while(i<ft_strlen(path)+ length+1)
	{
		fullpath[i++]=0;
	}
	ft_strncat(fullpath,path,ft_strlen(path));
	ft_strncat(fullpath,filename,length);
	return fullpath;
}
