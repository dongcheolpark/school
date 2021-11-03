#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char id[10];
	int passwd;
}member;

int search(member *, int);
void update(member *);
void print(member *, int);

int main(int argc, char **argv)
{
	int i, index;
	int num;
	int mem_num;
	member temp;
	member *list;

	if(argc != 2){
		printf("사용법 : ./member 5\n");
		return 0;
	}
	mem_num = atoi(argv[1]);

	list = (member *)malloc(sizeof(member) * mem_num);

	printf("-----각 회원 정보 입력-----\n");
	for(i = 0; i < mem_num; i++)
		scanf("%s%d", list[i].id, &list[i].passwd);

	while(1){
		printf("1. 검색\t2. 수정\t3. 전체 출력\t4. 종료 : ");
		scanf("%d", &num);
		switch(num){
			case 1:
				index = search(list, mem_num);
				printf("검색 내용 : ID -> %s, PASSWORD -> %d\n", list[index].id, list[index].passwd);
				break;
			case 2:
				index = search(list, mem_num);
				update(&list[index]);
				break;
			case 3:
				print(list, mem_num);
				break;
			default:
				return 0;
		}
	}
	return 0;
}
int search(member *list, int mem_num)
{
	char temp[10];
	int i, index;

	printf("ID 입력 : ");
	scanf("%s", temp);
	for(i = 0; i < mem_num; i++){
		if(!strcmp(list[i].id, temp)){
			index = i;
			break;
		}
	}
	return index;
}
void update(member *m)
{
	printf("update password : ");
	scanf("%d", &(m -> passwd));
}
void print(member *list, int mem_num)
{
	int i;
	for(i = 0; i < mem_num; i++){
		printf("ID -> %s, password -> %d\n", list[i].id, list[i].passwd);
	}
}
