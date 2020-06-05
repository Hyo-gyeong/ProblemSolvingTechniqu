#include <stdio.h>
#include <stdlib.h>

int matrixPath(int **m, int r, int c, int i, int j, int **M)
{
	if (i == 0 && j == 0)
		return m[i][j];
	else if (i == 0){
		if (M[0][j-1] == 0)
			M[0][j-1] = matrixPath(m, r, c, 0, j-1, M);
		return M[0][j-1] + m[i][j];
	}
	else if (j == 0){
		if (M[i-1][0] == 0)
			M[i-1][0] = matrixPath(m, r, c, i-1, 0, M);
		return M[i-1][0] + m[i][j];
	}
	else
	{
		if (M[i-1][j] == 0)
			M[i-1][j] = matrixPath(m, r, c, i-1, j, M);
		if (M[i][j-1] == 0)
			M[i][j-1] = matrixPath(m, r, c, i, j-1, M);
		return ((M[i-1][j] < M[i][j-1]) ? M[i-1][j] : M[i][j-1]) + m[i][j];
	}
}
int main(void) 
{ 
	int **m, **M;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix 

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	
	for(i = 0; i < r; i++ ){
		M[i] = (int*)malloc(sizeof(int*) * c);
		m[i] = (int*)malloc(sizeof(int) * c); 
	}

	for(i = 0; i < r; i++) 
		for(j = 0; j < c; j++){
			M[i][j] = 0;
			scanf("%d", &m[i][j]);
		}

	printf("%d\n", matrixPath(m, r, c, 3, 3, M));//index´Ï±î
	free(M);
}
