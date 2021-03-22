#include <stdio.h>

int main(void)
{
   int  a1, a2, a3, cnt;
   printf("정수 세 개를 입력 하세요 :  ");
   cnt = scanf("%d%d%d", &a1, &a2, &a3);
   printf("입력된 데이터 개수 : %d%d%d\n", a1,a2,a3);
   return 0;
}