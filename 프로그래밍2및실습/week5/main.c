#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char * str[10];
	int n = 10;
	for(int i = 0;i<n;i++) {
		char tmp[21];
		scanf("%s",tmp);
		str[i] = (char *)malloc(sizeof(char)*strlen(tmp));
		strcpy(str[i],tmp);
	}
	for(int i = 0;i<n;i++) {
		printf("%s\n",str[i]);
		free(str[i]);
	}
	return 0;
}