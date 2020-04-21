#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int *A, int c)
{
	int i;

	for (i = 0; i < c; i++)
		A[i] = rand() % 1000;
}
void printArray(int *A, int c)
{
	int i;

	for (i = 0; i < c; i++)
		printf("%4d", A[i]);
	printf("\n");
}
void bubbleSort(int *A, int n)
{
	int i, j;
	int temp;
	int flag;

	for (i = 0; i < n-1; i++){
		flag = 0;
		for (j = 0; j < n-i-1; j++)
			if (A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
		if (flag == 0)
			break;
		printf("%d :", i);
		printArray(A, n);
	}
}
int main(void)
{
	int count, i;
	int *A;
	//srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &count);

	A = (int*) malloc (sizeof(int) * count);
	if(!A) { 
		printf("메모리를할당할수없습니다."); 
		return 0; 
	}

	initArray(A, count);
	printArray(A, count);
	printf("\n정렬과정:\n");
	bubbleSort(A, count);

	free(A);
}