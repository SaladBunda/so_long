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
				main_game(map);
			}
			else
				printf("bad map");
		}
		else
			printf("not a .ber file");
	}
}