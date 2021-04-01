#include <cstdio>
#include <algorithm>

int main() {
    int n = 0,cnt[10001];
    for(int i = 0;i<=10000;i++) {
        cnt[i] = 0;
    }
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        int tmp = 0;
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    int i = 0;
    while(n--<=0) {
       int a = cnt[i];
       for(int j = 0;j<a;j++) {
           printf("%d ",i);
       }
       n -= a;
    }
    
    return 0;
}