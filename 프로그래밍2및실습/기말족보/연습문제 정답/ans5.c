#include <stdio.h>
struct profile{
	double height;
	double weight;
};

int main(void)
{
	struct profile p1;
	printf("키를 입력하세요 : ");
	scanf("%lf", &p1.height);
	printf("몸무게를 입력하세요 : ");
	scanf("%lf", &p1.weight);

	printf("키 : %.2lf\n", p1.height);
	printf("몸무게 : %.2lf\n", p1.weight);

	return 0;
}
