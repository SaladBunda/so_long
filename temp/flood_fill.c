#include <stdlib.h>
#include <stdio.h>


int is_notzero(char c)
{
	if(c == 'E'||c=='P'||c=='C'||c=='V')
		return 1;
	return 0;
}

void flood_fill(char *grid[], int start_x, int start_y, int height, int width) {
    if (start_x < 0 || start_x >= height || start_y < 0 || start_y >= width)
        return;
    
    if (grid[start_x][start_y] == '1')
        return;
    
    grid[start_x][start_y] = '1';

    flood_fill(grid, start_x + 1, start_y, height, width); // Down
    flood_fill(grid, start_x - 1, start_y, height, width); // Up
    flood_fill(grid, start_x, start_y + 1, height, width); // Right
    flood_fill(grid, start_x, start_y - 1, height, width); // Left
}
#include <stdlib.h>
#include <string.h>

int main()
{

	int i;
	char **tab=malloc(6*sizeof(char *));
  	tab[0]=strdup("11111");
  	tab[1]=strdup("1C101");
  	tab[2]=strdup("1P111");
  	tab[3]=strdup("100E1");
  	tab[4]=strdup("11111");
	tab[5]=NULL;
	flood_fill(tab,1,2,5,5);
	i=0;
	while(tab[i])
	{
		printf("%s\n",tab[i++]);
	}
}
	// char **tab = malloc(size.y * sizeof(char *));
    // for (int i = 0; i < size.y; i++) {
    //     tab[i] = malloc(size.x * sizeof(char));
    //     for (int j = 0; j < size.x; j++) {
    //         tab[i][j] = (i == j) ? 'X' : 'O';
    //     }
    // }