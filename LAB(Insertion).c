#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *A, int c)
{
	int i;

	for (i = 0; i < c; i++)
		printf("%4d", A[i]);
	printf("\n");
}
void insertionSort(int *A, int n)
{
	int i, j;
	int temp;

	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++){
			if (A[i] < A[j]){
				temp = A[i];
				while (i > j){
					A[i] = A[i-1];
					i--;
				}
				A[j] = temp;
			}
		}

}
void initArray(int *A, int c)
{
	int i;
	srand(time(NULL));

	for (i = 0; i < c; i++)
		A[i] = rand() % 1000;
}
int main(void)
{
	int *A;
	int num;

	printf("Enter a number : ");
	scanf("%d", &num);

	A = (int*) malloc (sizeof(int) * num);

	initArray(A, num); 
	printArray(A, num);
	insertionSort(A, num);
	printArray(A, num);

	free(A);
}