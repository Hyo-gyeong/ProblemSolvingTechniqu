#include <stdio.h>
void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex;
	int i;

	if (toPick == 0){//���̻� ������ ������ 
		for (i = 0; i < m; i++)//����Ʈ�ϰ�
			printf("%d  ", picked[i]);
		printf("\n");
		return;				//�Լ� Ż��
	}
	lastIndex = m - toPick - 1;//�� ä���� �ϴ� index�� ��index

	if (m == toPick)//ó������ ä�����
		smallest = 0;//0���� ����
	else				//�׷��� ������
		smallest = picked[lastIndex]+1;//���� �ͺ��� �ϳ�ū ��

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