#include <stdio.h>
#include <stdlib.h>

void printArray(int picked[], int m)
{
	int i;

	for (i = 0; i < m; i++)
		printf("%d ", picked[i]);
	printf("\n");
	return;
}
void pick(int n, int m, int picked[], int toPick)
{
	int lastIndex, smallest;
	int i;

	if (toPick == 0){//다 골랐으면
		printArray(picked, m);
		return;
	}
	
	lastIndex = m - toPick -1;//채워진 index의 앞

	if (m == toPick)//처음
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++){
		picked[lastIndex + 1] = i; 
		pick(n, m, picked, toPick-1);
	}
}
int main(void)
{
	int n, m;
	int *picked;

	printf("Enter n and m : (n >= m)");
	scanf("%d %d", &n, &m);
	picked = (int*) malloc (sizeof(int) * (m * n));
	
	pick(n, m, picked, m);

	free(picked);
}