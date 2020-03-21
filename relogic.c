#include <stdio.h>
#define SIZE 12
//소수인 경우 1을 아닌 경우 0을 반환하는 함수
//int isPrime(int n)을 정의하라
int isPrime(int n)
{ 
    int i;

    for (i = 2; i < n - 1; i++) // (i = 2; i < n / 2; i++)로 하면 더 효율적 
        if (n % i == 0)
            return 0;
    return 1;
}
//두 개의 배열 a, b가 같으면 1을, 같지 않으면 0을 반환하는 함수를
//작성하라. aSize, bSize는 각각 배열 a와 b의 크기이다.
int equalArray(int a[], int aSize, int b[], int bSize)
{
	int i, j;

	if (aSize == bSize){
		for (i = 0; i < aSize; i++)
			for (j = 0; j < aSize; j++)
				if (j == aSize)
					return 0;
		return 1;
	}
	else
		return 0;
}

//배열 a에 key가 있으면 그 인덱스를, 없으면 -1을 반환하는 함수 search를 작성하라.
//aSize는 각각 배열 a의 크기이다
int search(int a[], int sizeA, int key)
{
	int i;

	for (i = 0; i < sizeA; i++)
		if (a[i] == key)
			return i;
	return -1;
}
int main(void)
{
	int num;

	int arr1[100], arr2[100];
	int size1, size2, element, i;

	int a[12] = {11, 22, 33, 44, 55, 66, 11, 22, 33, 44, 55, 66};
	int key;

	//소수 판별
	printf("Enter a number: ");
	scanf("%d", &num);

	if (isPrime(num))
		printf("%d is a prime number\n", num);
	else
		printf("%d is not a prime number\n", num);

	//배열 비교
	printf("Enter an array1 size: ");
	scanf("%d", &size1);

	i = 0;
	while(i < size1){
		printf("Enter element %d : ", i+1);
		scanf("%d", &element);
		arr1[i] = element;
		i++;
	}

	printf("Enter an array2 size: ");
	scanf("%d", &size2);

	i = 0;
	while(i < size2){
		printf("Enter element %d : ", i+1);
		scanf("%d", &element);
		arr2[i] = element;
		i++;
	}

	if (equalArray(arr1, size1, arr2, size2))
		printf("Two arrays are same\n");
	else
		printf("Two arrays are not same\n");

	//key값 유무
	printf("Enter a key: ");
	scanf("%d", &key);

	if (search(a, SIZE, key) == -1)
		printf("There is no %d\n", key);
	else
		printf("%d is in index %d\n", key, search(a, SIZE, key));
}