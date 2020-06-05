#include <stdio.h>
#include <stdlib.h>

int H(int n, int *M) 
{
	int i;
	int rslt = 0;

	if (n == 0 || n == 1){
		return 1;
	}
	else{
		if (M[n] == 0)
			for (i = 0; i < n; i++)
				M[n] += H(i, M) * H(n-i-1, M);
		return M[n];
	}
}
int main(void)
{ 
	int n, i; 
	int *M;
	
	printf("0보다큰정수:"); 
	scanf("%d", &n); 

	M = (int*)malloc(sizeof(int) * (n+1));
	for (i = 0; i <= n; i++)
		M[i] = 0;

	printf("결과는%d\n", H(n, M));
}