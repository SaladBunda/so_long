#include "so_long.h"

int main(int ac, char **av)
{
	t_map map;
	
	if(ac > 2 || ac == 1)
	{
		printf("incorrect arg");
		return 0;
	}
	else
	{
		if(ext_test(av[1])==1)
		{
			printf("its a map\n");
			if(map_tests(av[1],&map)==1)
			{
				int i = 0;
				while(map.lines[i])
					printf("%s\n",map.lines[i++]);
				main_game(map);
				printf("good map\n");
				printf("width:%d\nheight:%d\n",map.x,map.y);
			}
			else
				printf("bad map");
		}
		else
			printf("not a .ber file");
	}
}