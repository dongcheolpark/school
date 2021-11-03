#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define N 4

//<header>
typedef struct {
	int x;
	int y;
}pos;
int getch(void);
bool check(int ** arr,int chk_move);
void setup(int ** arr,int num);
void swap(int * a,int * b);
bool move(int ** arr,int arrow);
void print(int ** arr);
//</header>

//<variable>
pos move_arr[4] = {{1,0},{0,1},{-1,0},{0,-1}}; 
char * blank = "    ";
//</variable>

//<Main>

int main(int argc,char * argv[]) {
	int ** arr;
	arr = (int **)malloc(sizeof(int *)*N);
	//setup
	for(int i = 0;i<N;i++) {
		arr[i] = (int *)malloc(sizeof(int)*N);
	}
	if(atoi(argv[1]) == 1) {
		setup(arr,1);
	}	
	else if (atoi(argv[1]) == 2) {
		setup(arr,2);
	}

	//main program
	bool chk_move = 0;
	do{
		system("clear");
		print(arr);
		char a = getch();
		chk_move = 0;
		if(a == 'q') {
			printf("프로그램을 종료합니다.");
			return 0;
		}
		else if(a == 'i') chk_move = move(arr,0);
		else if(a == 'j') chk_move = move(arr,1);
		else if(a == 'k') chk_move = move(arr,2);
		else if(a == 'l') chk_move = move(arr,3);
		if(!chk_move) continue;
	}while(!check(arr,chk_move));
	system("clear");
	print(arr);
	printf("축하합니다!\n");
	sleep(3);
	return 0;
}

//</Main>

//<function>
int getch(void) {
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}

bool check(int ** arr,int chk_move) {
	if(!chk_move) return 0;
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<N;j++) {
			if(arr[i][j] == (i*N)+j+1) continue; 
			else if(i == N-1&&j == N-1) continue;
			else return 0;
		}
	}
	return 1;
}

void swap(int * a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void setup(int ** arr,int num) {
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<N;j++) {
			if(i == N-1 && j == N-1) arr[i][j] = 0; 
			else arr[i][j] = (N*i)+j+1;
		}
	}
	if(num == 2) {
		srand((unsigned)time(NULL));
		for(int i = 0;i<15;i++) {
			int randNum = rand()%15;
			swap(*(arr + i/4)+i%4,*(arr+randNum/4)+randNum%4);
		}
	}
}

bool move(int ** arr,int arrow) {
	pos a = {0,0};
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<N;j++) {
			if(arr[i][j] == 0) {
				a.x = i;
				a.y = j;
			}
		}
	}
	pos b = {a.x + move_arr[arrow].x,a.y + move_arr[arrow].y};
	if(b.x < 0 || N <= b.x || b.y < 0 || N <= b.y) return 0;
	swap(&arr[a.x][a.y],&arr[b.x][b.y]);
	return 1;
}

void print(int ** arr) {
	for(int i = 0;i<N;i++) {
		printf("          ");
		for(int j = 0;j<N;j++) {
			if(arr[i][j] == 0) printf("%s",blank);
			else printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}
//</function>
