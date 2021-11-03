#include <stdio.h>

struct student{
	int num;
	char name[20];
	int score[5];
	double avg;
};

struct student average(struct student);

int main(void)
{
	struct student s1;
	int i;

	printf("학번을 입력하세요 : ");
	scanf("%d", &s1.num);
	printf("이름을 입력하세요 : ");
	scanf("%s", s1.name);

	for(i = 0; i < 5; i++){
		printf("%d 번째 점수를 입력하세요 : ", i + 1);
		scanf("%d", &s1.score[i]);
	}

	s1 = average(s1);

	printf("----------------------------------\n");

	printf("학번 : %d\n", s1.num);
	printf("이름 : %s\n", s1.name);

	for(i = 0; i < 5; i++){
		printf("%d 번째 점수 : %d\n", i + 1, s1.score[i]);
	}
	printf("평균 점수 : %.2lf\n\n", s1.avg);
	return 0;
}
struct student average(struct student s)
{
	int total = 0;
	int i;

	for(i = 0; i < 5; i++){
		total += s.score[i];
	}
	s.avg = total / 5.0;
	return s;
}
