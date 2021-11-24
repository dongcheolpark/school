#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//<header>
typedef struct word{
	char eng_word[20];
	char kor_word[70];
}word;// 15+5, 30*2 + 10
typedef struct linked_list {
	struct word * node;
	struct linked_list * next;
}linked_list;

linked_list * read_dictionary();
void sort(linked_list *);
void print_list(linked_list *);
void compare_and_swap(linked_list *,linked_list *);
void delete_list(linked_list *);
int word_check(linked_list *);
//</header>

//<function>
linked_list * read_dictionary() {
	FILE * ifp = fopen("dic.txt","r");
	linked_list * list, * res_list = NULL, * data;
	while(1) {
		data = (linked_list *)malloc(sizeof(linked_list));
		data->node = (word*)malloc(sizeof(word));
		data->next = NULL;
		if(fscanf(ifp,"%s %s",data->node->eng_word,data->node->kor_word) == EOF) break;
		if(res_list == NULL) res_list = data;
		else list->next = data;
		list = data;
	}
	return res_list;
}

void sort(linked_list * list) {
	for(linked_list * item1 = list;item1 != NULL;item1 = item1->next) {
		for(linked_list * item2 = item1->next;item2 != NULL;item2 = item2->next) {
			compare_and_swap(item1,item2);
		}
	}
}

void compare_and_swap(linked_list * l,linked_list *r) {
	if(strcmp(l->node->eng_word,r->node->eng_word) > 0) {
		//swap
		word * node = l->node;
		l->node = r->node;
		r->node = node;
	}
}

void print_list(linked_list * list) {
	for(linked_list * i = list;i != NULL;i = i->next) {
		printf("%s %s\n",i->node->eng_word,i->node->kor_word);
	}
	puts("");
}

void delete_list(linked_list * list) {
	if(list == NULL) return;
	delete_list(list->next);
	free(list->node);
	free(list);
	return;
} 

int word_check(linked_list * list) {
	int score = 0;
	for(linked_list * i = list;i != NULL;i = i->next) {
		int chk = 0;
		printf("%s\n",i->node->kor_word);
		char tmp[20];
		scanf("%s",tmp);
		if(strcmp(tmp,".quit") == 0) return score;
		chk = strcmp(i->node->eng_word,tmp);
		if(chk != 0) {
			printf("incorrect!\n");
		}
		else {
			score++;
			printf("correct!\n");
		}
		puts("");
	}
	printf("모두 수행하셨습니다.\n");
	return score;
}

int main() {
	linked_list * list = read_dictionary();
	sort(list);
	printf("        1.영어 단어 맞추기\n");
	printf("        2.종료\n");
	int tmp;
	scanf("%d",&tmp);
	if(tmp == 1) {
		printf("점수는 %d점 입니다.\n",word_check(list));
	}
	printf("종료합니다.\n");
	sleep(3);
	system("clear");
	delete_list(list);
	return 0;
}
//</function>