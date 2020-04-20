#include <stdio.h>

int max1(int list[], int low, int high)//반복
{
	int i;
	int max;

	if (low == high)
		return list[low];

	else if (low < high){
		max = list[low];
		for (i = low; i < high; i++)
			if (max < list[i+1])
				max = list[i+1];
		return max;
	}
}
int max2(int list[], int low, int high)//재귀
{
	int n1, n2;
	int mid;

	if (low == high)
		return list[low];

	mid = (low + high) / 2;

	n1 = max2(list, low, mid);//반의 왼쪽에서 최대찾기
	n2 = max2(list, mid+1, high);//반의 오른쪽에서 최대찾기

	//if (n1 > n2)
	//	return n1;
	//else
	//	return n2;
	
	return n1 >= n2 ? n1 : n2; //더 간결
}
int main(void)
{
	int list[] = {10, 20, 100, 4, 5, 45, 3, 99, 11, 22};

	printf("가장큰수는%d\n", max1(list, 0, 9)); // 100 
	printf("가장큰수는%d\n", max2(list, 0, 9)); // 100

	printf("가장큰수는%d\n", max1(list, 5, 9)); // 99 
	printf("가장큰수는%d\n", max2(list, 5, 9)); // 99

	printf("가장큰수는%d\n", max1(list, 3, 6)); // 45 
	printf("가장큰수는%d\n", max2(list, 3, 6)); // 45
}
