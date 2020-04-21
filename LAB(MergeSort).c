#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *list, *Mlist;

void initArray(int *list, int n)
{
	int i;

	for (i = 0; i < n; i++)
		list[i] = rand() % 1000;
}
void printList(int list[], int minIndex, int maxIndex)
{
	int i;

	for (i = minIndex; i < maxIndex; i++)
		printf("%d  ", list[i]);
	printf("\n");
}
void merge(int list[], int minIndex, int middle, int maxIndex)
{
	int i = minIndex, j = middle+1;
	int k = minIndex;

	while (i <= middle && j <= maxIndex){
		if (list[i] < list[j])
			Mlist[k++] = list[i++];
		else
			Mlist[k++] = list[j++];
	}

	if (j > maxIndex)
		while (i <= middle) Mlist[k++] = list[i++];
	else 
		while (j <= maxIndex) Mlist[k++] = list[j++];

	for (k = minIndex; k <= maxIndex; k++)
		list[k] = Mlist[k];
}
void mergeSort(int *list, int minIndex, int maxIndex)
{
	int middle;

	if (minIndex < maxIndex){
		middle = (minIndex + maxIndex) / 2;
		mergeSort(list, minIndex, middle);
		mergeSort(list, middle+1, maxIndex);
		merge(list, minIndex, middle, maxIndex);	
	}
}
int main(void)
{
	int num, i;

	printf("Enter a number : ");
	scanf("%d", &num);

	list = (int*) malloc (sizeof(int) * num);
	Mlist = (int*) malloc (sizeof(int) * num);

	initArray(list, num);
	printList(list, 0, num);
	mergeSort(list, 0, num-1);
	printList(list, 0, num);

	free(list);
	free(Mlist);
}