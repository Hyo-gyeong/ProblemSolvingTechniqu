#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void bucketInit(int *b, int nSize)
{
	int i;

	for (i = 0; i < nSize; i++)
		b[i] = i+1;
}
int pick(int *items, int itemSize, int* bucket, int bucketSize, int k, int target) 
{ 
	int i,lastIndex, smallest;
	int total = 0;
	int found = FALSE;

	if (k == 0){
		for (i = 0; i < bucketSize; i++)
			total += bucket[i];
		if (total == target){
			for (i = 0; i < bucketSize; i++){
				if (bucket[i] < 0)
					printf("%d ", bucket[i]);
				else
					printf("+%d ", bucket[i]);
			}
			printf("\n");
			return TRUE;
		}
		return FALSE;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;	

	for(i = smallest; i < itemSize; i++){
		bucket[lastIndex+1] *= items[i];
		found = pick(items, itemSize, bucket,bucketSize, k - 1, target) || found;
	}
	return found;
}
int main(void)
{
	int items[] = {1, -1}; // 혹은 char items[] = {'+', '-'};
	int *bucket;
	int target;
	int i, sum = 0;
	int minBucketSize;
	int found = 0;

	printf("목적의 합을 입력 ");
	scanf("%d", &target);

	bucket = (int *)malloc(sizeof(int) * target);
	bucketInit(bucket, target);
	for (i = 1; sum <= target; i++)
		sum += i;

	minBucketSize = i - 2; //index니까 -1, i++되고 내려오니까 -1, 총 -2

	for (i = minBucketSize; !found; i++)
		found = pick(items, 2, bucket, i, i, target);
}
