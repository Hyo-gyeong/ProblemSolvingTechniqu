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
	printf("학번 국어 수학 영어\n");
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

	printf("\n**학생들의 성적**\n\n");
	i = 0;
	while (i < num){
		addInfo(s, i+1);
		printInfo(s);
		s += 1;
		i++;
	}
	
	s = s-num; //포인터 처음 index가리킴

	printf("\n**국어 성적으로 정렬 후**\n\n");
	selectionSort(s, num);	
	i = 0;
	while (i < num){
		printInfo(s);
		s += 1;
		i++;
	}
	s = s-num; //포인터를 원 위치로 갖다놔야 메모리 돌려줄 수 있고 assertion failure에러 나지 않음
	free(s);
}