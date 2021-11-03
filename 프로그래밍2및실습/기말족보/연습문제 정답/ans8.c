#include <stdio.h>

struct profile{
	char name[20];
	double grade;
	int english;
};

void input_data(struct profile *);
void elite(struct profile *);

int main(void)
{
	struct profile new_staff[5];
	input_data(new_staff);
	elite(new_staff);
	return 0;
}

void input_data(struct profile *sp)
{
	int i;
	for(i = 0; i < 5; i++)
		scanf("%s%lf%d", (sp+i) -> name, &(sp+i) -> grade, &(sp+i) -> english);
}

void elite(struct profile *sp)
{
	int i;
	printf("=====엘리트 사원=====\n");
	for( i = 0; i < 5; i++){
		if(((sp+i) -> grade >= 4.0) && ((sp+i) -> english >= 900)){
			printf("이름 : %s\n", (sp+i) -> name);
			printf("학점 : %.2lf\n", (sp+i) -> grade);
			printf("영어점수 : %d\n\n", (sp+i) -> english);
		}
	}
}
