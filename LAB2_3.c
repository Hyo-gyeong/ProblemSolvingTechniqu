#include <stdio.h>
int H(int i)
{
	int k;
	int temp = 0;

	if (i == 0 || i == 1)
		return 1;
	else{
		for (k = 0; k < i; k++)
			temp += H(k)*H(i-k-1);
		return temp;
	}
}
int main(void)
{
	int input;

	printf("Enter a number: ");
	scanf("%d", &input);

	printf("%d\n", H(input));
}