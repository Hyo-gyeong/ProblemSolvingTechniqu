#include <stdio.h>
#include <stdlib.h>

int kBonacci(int k, int n)
{
	int i;
	int temp = 0;

	if (n > k){
		for (i = 1; i <= k; i++)
			temp += kBonacci(k, n-i);
		return temp;
	}
	else
		for (i = 1; i < k; i++)
			return 1;
}
int main(void)
{
	int k, n;

	printf("ют╥б: ");
	scanf("%d %d", &k, &n);

	printf("%d",kBonacci(k, n));
}