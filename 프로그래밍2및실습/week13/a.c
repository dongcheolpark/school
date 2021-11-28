#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 20

struct linked_list {

char d;

struct linked_list *next;

};

typedef struct linked_list ELEMENT;

typedef ELEMENT *LINK;

LINK string_to_list(char s[]) {
	 LINK head=NULL, node, last;
    int i = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='\0')  break;
        else{
            node = malloc(sizeof(ELEMENT));
            node -> d = s[i];
            node -> next = NULL;
        }
        if(head=NULL)   head = node;
        else last -> next = node;
        last = node;
    }
	return head;
}

void print_list(LINK head) {

if (head == NULL)

printf("NULL \n");

else {

printf("%c --> ", head -> d);

print_list(head -> next);

}

}

int main(void) {

char input[N];

LINK h;

int i=1;
while(i){
printf("문자열 입력: ");

scanf("%s", input);

if(strcmp(input, "exit")==0){
    printf("BYE......\n");
    i=0;
}

else{
h = string_to_list(input);

printf("변환 리스트 결과 : \n");

print_list(h);
}

}

return 0;
}