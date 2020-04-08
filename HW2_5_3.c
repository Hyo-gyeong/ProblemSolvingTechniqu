#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10
int screen[WIDTH][HEIGHT] = { 
	0, 0, 0,-1,-1,-1,-1,-1,-1,-1, 
	-1,-1, 0,-1,-1,-1,-1,-1,-1,-1, 
	-1, 0, 0, 0, 0, 0, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1, 0, 0, 0,-1, 0, 0, 0,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1, 0,-1, 
	-1,-1,-1,-1, 0,-1,-1,-1, 0,-1, 
	-1,-1,-1,-1, 0, 0, 0, 0, 0, 0 
};
static int count = 1;

void print_screen(int screen[][HEIGHT])
{
	int i, j;

	for (i = 0; i < WIDTH; i++){
		for (j = 0; j < HEIGHT; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}
	printf("\n");
}
void flood_fill(int x, int y)
{	
	if (0 > y || HEIGHT <= y || 0 > x || WIDTH <= x)
		return;
	else if (screen[x][y] == 0){

		screen[x][y] = count++;

		flood_fill(x, y+1);//3
		flood_fill(x+1, y);//6
		flood_fill(x, y-1);//9
		flood_fill(x-1, y);//12
	}
}
int main(void)
{
	print_screen(screen);
	flood_fill(0, 0, 0);
	print_screen(screen);
}