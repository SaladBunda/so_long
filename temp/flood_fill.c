#include <stdlib.h>
#include <stdio.h>


int is_notzero(char c)
{
	if(c == 'E'||c=='P'||c=='C'||c=='0')
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
// void flood_fill(char *map[],int width,int height)
// {
// 	int i=1;
// 	int j =1;
// 	while(i<height-1)
// 	{
// 		j=1;
// 		while(j<width - 1)
// 		{
// 			if(map[i][j]=='1')
// 			{
// 				j++;
// 			}
// 			else{

// 				if(is_notzero(map[i+1][j])==1 || is_notzero(map[i-1][j])==1 || is_notzero(map[i][j+1])==1 || is_notzero(map[i][j-1])==1)
// 					map[i][j]='V';
// 				j++;
// 			}
// 		}
// 		i++;
// 	}

// }
#include <stdlib.h>
#include <string.h>

int main()
{

	int i;
	char **tab=malloc(5*sizeof(char *));
  	tab[0]=strdup("111111111");
  	tab[1]=strdup("1C0000101");
  	tab[2]=strdup("1P0001101");
  	tab[3]=strdup("10101E101");
  	tab[4]=strdup("111111111");
	flood_fill(tab,2,3,5,10);
	i=0;
	while(i<5)
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