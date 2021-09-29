#include <stdio.h>

void func(int a, int b, int c[ ]) {
	c[0] = a/b;
	c[1] = a%b;
}

int main() {
	int a = 10,b = 3,c[2];//임의의 상수 a,b
	func(a,b,c);
	printf("%d %d",c[0],c[1]);
}