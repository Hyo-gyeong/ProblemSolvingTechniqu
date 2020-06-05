#include<stdio.h> 

int comb(int n, int r) 
{ 
	if (r == 0 || r == n)
		return 1;
	else{
		printf("comb(%d,%d) = %d\n",n,r,  comb(n-1, r-1) + comb(n-1, r));
		return comb(n-1, r-1) + comb(n-1, r);
	}
}
int main(void) 
{
	int n, r;

	printf("nCr의 n과 r입력 : ");
	scanf("%d %d", &n, &r);
   
	printf("%d\n", comb(n,r));
	return 0; 
}