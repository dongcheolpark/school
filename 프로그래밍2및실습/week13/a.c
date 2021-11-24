#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20

struct linked_list
{
	char d;
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;

typedef ELEMENT *LINK;

LINK string_to_list(char s[])
{
	LINK head,prev,node;
	if (s[0] == '\0')
		return NULL;
	else {
		for(int i = 0;s[i] != '\0';i++) {
			node = malloc(sizeof(ELEMENT));
			if(i == 0) 
				head = node;
			else 
				prev->next = node;
			node->d = s[i];
			node->next = NULL;
			prev = node;
		}
	}
	return head;
}
void free_linked_list(LINK h) {
	if(h == NULL) return;
	free_linked_list(h->next);
	free(h);
}
void print_list(LINK head)
{
	if (head == NULL)
		printf("NULL \n");
	else
	{
		printf("%c --> ", head->d);
		print_list(head->next);
	}
}

int main(void)
{
	char input[N];
	while(1) {
		LINK h;
		printf("문자열 입력: ");
		scanf("%s", input);
		if(strcmp(input,"exit") == 0) {
			puts("BYE......");
			break;
		}
		h = string_to_list(input);
		printf("변환 리스트 결과 : \n");
		print_list(h);
		free_linked_list(h);
	}
	return 0;
}