#include <stdio.h>
int get_cycle_number(int n)
{
	if (n == 1){
		printf("%3d", n);
		return 1;
	}
	else if (n % 2 == 0){//짝수일때
		printf("%3d", n);
		return 1 + get_cycle_number(n/2);
	}
	else {
		printf("%3d", n);
		return 1 + get_cycle_number(3*n + 1);
	}		
}
int main(void)
{
	int cycleNum;

	printf("Enter a number: ");
	scanf("%d", &cycleNum);

	printf("\n길이: %d\n", get_cycle_number(cycleNum));
}