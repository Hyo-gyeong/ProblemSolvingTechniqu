#include <stdio.h> 
#include <stdlib.h>

int comb(int n, int r, int **M) 
{ 
	if (r == 0 || r == n)
		return 1;
	else{
		//printf("comb(%d,%d)\n",n,r);
		if (M[n][r] == 0)
			M[n][r] = comb(n-1, r-1, M) + comb(n-1, r, M);
		return M[n][r];
	}
}
int main(void) 
{
	int n, r;
	int i, j;
	int **M;

	printf("nCr의 n과 r입력 : ");
	scanf("%d %d", &n, &r);
   
	M = (int**)malloc(sizeof(int*) * (n+1));

	for (i = 1; i <= n; i++)
		M[i] = (int*)malloc(sizeof(int) * (r+1));
		
	for (i = 1; i <= n; i++)
		for (j = 1; j <= r; j++)
			M[i][j] = 0;

	printf("%d\n", comb(n, r, M));

	free(M);
	return 0; 
}