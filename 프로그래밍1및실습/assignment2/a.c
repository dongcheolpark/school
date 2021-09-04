#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 5;
    int m = 46;
    int arr[5][45],chk[46];
    srand((unsigned)time(NULL));
    for(int i = 0;i<m;i++) {
        chk[i] = 0;
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            arr[i][j] = 0;
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            do {
                int tmp = rand()%45+1;
                if(chk[tmp]) continue;
                else {
                    chk[tmp]=1;
                    arr[i][tmp] = 1;
                    break;
                }
            } while(1); 
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 1;j<m;j++) {
            if(arr[i][j]) {
                printf("%d, ",j);
            }
        }
        puts("");
    }
}