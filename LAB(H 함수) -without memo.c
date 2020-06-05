#include <stdio.h>
int H(int n) 
{
	int i;
	int rslt = 0;

	if (n == 0 || n == 1)
		return 1;
	else{
		for (i = 0; i < n; i++)
			rslt += H(i)*H(n-i-1);
		return rslt;
	}
}
int main(void)
{ 
	int input; 
	
	printf("0보다큰정수:"); 
	scanf("%d", &input); 
	printf("결과는%d\n", H(input));
}