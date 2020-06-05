#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int M[])
{
	if (n == 1 || n == 2){
		M[n] = 1;
		return 1;
	}
	else{
		M[n] = fibo(n-1, M) + fibo(n-2, M);
		return M[n];
	}
}
int main(void)
{
	int input;
	int i;
	int *M;

	printf("몇 번째 까지의 피보나치 수열: ");
	scanf("%d", &input);

	M = (int*)malloc(sizeof(int) * (input+1));

	for (i = 1; i <= input; i++)
		printf("%d  ",fibo(i, M));
	printf("\n");

	free(M);
}