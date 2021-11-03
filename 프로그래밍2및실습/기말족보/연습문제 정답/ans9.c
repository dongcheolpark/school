#include <stdio.h>
#define N 3

typedef struct{
	char name[10];
	int num;
	double grade;
	char grade_ch[3];
}student;

void input_data(student *);
void output_data(student *);
void sort(student *);
double transfer(char *);

int main(void)
{
	student s[N];
	printf("------input------\n");
	input_data(s);
	sort(s);
	printf("------output-----\n");
	output_data(s);
	return 0;
}

double transfer(char *ch)
{
	if(strcmp(ch, "A+") == 0)
		return 4.5;
	else if(strcmp(ch, "A0") == 0)
		return 4.3;
	else if(strcmp(ch, "A-") == 0)
		return 4.0;
	else if(strcmp(ch, "B+") == 0)
		return 3.5;
	else if(strcmp(ch, "B0") == 0)
		return 3.3;
	else if(strcmp(ch, "B-") == 0)
		return 3.0;
	else if(strcmp(ch, "C+") == 0)
		return 2.5;
	else if(strcmp(ch, "C0") == 0)
		return 2.3;
	else if(strcmp(ch, "C-") == 0)
		return 2.0;
	else if(strcmp(ch, "D+") == 0)
		return 1.5;
	else if(strcmp(ch, "D0") == 0)
		return 1.3;
	else if(strcmp(ch, "D-") == 0)
		return 1.0;
	else if(strcmp(ch, "F") == 0)
		return 0.0;
}

void input_data(student *s)
{
	int i;
	for(i = 0; i < N; i++){
		scanf("%s%d%s", (s+i) -> name, &(s+i) -> num, (s+i) -> grade_ch);
		(s+i) -> grade = transfer((s+i) -> grade_ch);
	}
}

void output_data(student *s)
{
	int i;
	for(i = 0; i < N; i++)
		printf("%-10s	%d	%s\n", (s+i) -> name, (s+i) -> num, (s+i) -> grade_ch);
}

void sort(student *s)
{
	int i, j;
	student temp;
	for(i = 0; i < N-1; i++){
		for(j = N-1; j > i; j--){
			if(s[j-1].grade < s[j].grade){
				temp = s[j-1];
				s[j-1] = s[j];
				s[j] = temp;
			}
		}
	}
}
