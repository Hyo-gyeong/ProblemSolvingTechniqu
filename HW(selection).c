typedef struct student{
	int stdnum;
	int korean;
	int math;
	int english;
}Student;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(Student *s, int num)
{
	int i, j;
	int max;
	Student tmp;

	for (i = 0; i < num-1; i++){
		max = i;
		for (j = i; j < num-1; j++) 
			if (s[max].korean < s[j+1].korean)
				max = j+1;
		if (max != i){
			tmp = s[i];
			s[i] = s[max];
			s[max] = tmp;
		}
	}
}
void printInfo(Student *s)
{
	printf("�й� ���� ���� ����\n");
	printf("%2d %5d%5d%5d\n",s->stdnum, s->korean, s->math, s->english);
}
void addInfo(Student *s, int i) 
{
	s->stdnum = i;
	s->korean = rand() % 101;
	s->math = rand() % 101;
	s->english = rand() % 101;
}
int main(void)
{
	Student student;
	Student *s = &student;
	int num, i;
	srand(time(NULL));

	printf("Enter the number of students : ");
	scanf("%d", &num);
	s = (Student*) malloc (sizeof(Student) * num);

	printf("\n**�л����� ����**\n\n");
	i = 0;
	while (i < num){
		addInfo(s, i+1);
		printInfo(s);
		s += 1;
		i++;
	}
	
	s = s-num; //������ ó�� index����Ŵ

	printf("\n**���� �������� ���� ��**\n\n");
	selectionSort(s, num);	
	i = 0;
	while (i < num){
		printInfo(s);
		s += 1;
		i++;
	}
	s = s-num; //�����͸� �� ��ġ�� ���ٳ��� �޸� ������ �� �ְ� assertion failure���� ���� ����
	free(s);
}