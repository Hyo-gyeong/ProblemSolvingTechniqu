#include <stdio.h>

void printRslt(int n1, int n5, int n10)
{
	int i;

	for (i = 0; i < n1; i++)
		printf("1000 ");
	for (i = 0; i < n5; i++)
		printf("5000 ");
	for (i = 0; i < n10; i++)
		printf("10000 ");
	printf("\n");
}
void pick(int money, int n5, int n10)
{
	int i;
	int sum = n5 / 2;

	if (money < 5000){
		printRslt(money/1000, n5, n10);
		if (sum > 0)
			printRslt(money/1000, n5 % 2, sum);
	}
	else {
		printRslt(money/1000, n5, n10);
		if (sum > 0)
			printRslt(money/1000, n5 % 2, sum);
		money -= 5000;
		pick(money, n5+1, n10);
	}
}
int main(void)
{
	int money;

	printf("¼¼¹îµ·: ");
	scanf("%d", &money);

	pick(money, 0, 0);
}