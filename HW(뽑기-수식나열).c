#include <stdio.h>
#include <stdlib.h>

void printExpr(int *A)
{
	printf("+%d+%d = %d\n", A[0], A[1], A[0]+A[1]);
	printf("+%d-%d = %d\n", A[0], A[1], A[0]-A[1]);
	printf("-%d+%d = %d\n", A[0], A[1], -A[0]+A[1]);
	printf("-%d-%d = %d\n", A[0], A[1], -A[0]-A[1]);
	return;
}
void pick(int input, int *A, int toPick, int k)
{
	int smallest;
	int lastIndex;
	int i, j;
	int flag = 0;

	if (k == 0){
		printExpr(A);
		return;
	}

	lastIndex = toPick - k - 1;

	if (k == toPick) //처음
		smallest = 1;
	else
		smallest = A[lastIndex] + 1;

	for (i = smallest; i <= input; i++){
		for(j = 0; j < lastIndex+1; j++)
			if (A[j] == i)
				flag = 1;
		if (flag == 1)
			continue;
		A[lastIndex+1] = i;
		pick(input, A, toPick, k-1);
	}
}
int main(void)
{
	int *A;
	int input;

	printf("입력 : ");
	scanf("%d", &input);

	A = (int*) malloc (sizeof(int) * input);

	pick(input, A, 2, 2);

	free(A);
}