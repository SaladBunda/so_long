/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:33 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/02/21 18:32:35 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void start_position(char *map[],int *x, int *y)
{
	int i =1;
	int j;
	while(map[i+1])
	{
		j=1;
		while(map[i][j+1])
		{
			if(map[i][j]=='P')
			{
				*x = j;
				*y=i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int parsing_test(char *map[], int width, int height)
{
	int x;
	int y;
	(void )width;
	(void) height;
	start_position(map,&x,&y);
	printf("x:%d y:%d\n",x,y);
	return 1;
}
