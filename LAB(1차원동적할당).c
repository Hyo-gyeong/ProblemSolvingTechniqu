#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int *A, int n)
{
	int i;

	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;
}
void printArray(int *A, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int *A;
	int n;
	srand(time(NULL));

	printf("Enter  a number: ");
	scanf("%d", &n);

	A = (int*) malloc (sizeof(int) * n);

	initArray(A, n);
	printArray(A, n);
	free(A);
}