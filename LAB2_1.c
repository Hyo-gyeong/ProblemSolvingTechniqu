#include <stdio.h>
void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex;
	int i;

	if (toPick == 0){//더이상 고를것이 없으면 
		for (i = 0; i < m; i++)//프린트하고
			printf("%d  ", picked[i]);
		printf("\n");
		return;				//함수 탈출
	}
	lastIndex = m - toPick - 1;//는 채워야 하는 index의 전index

	if (m == toPick)//처음부터 채우려면
		smallest = 0;//0부터 시작
	else				//그렇지 않으면
		smallest = picked[lastIndex]+1;//이전 것보다 하나큰 수

	for (i = smallest; i < n; i++){
		picked[lastIndex+1] = i;
		pick(n, m, picked, toPick-1);
	}
}
int main(void)
{
	int picked[4];
	pick(7, 4, picked, 4);
}