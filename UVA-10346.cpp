#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!= EOF){
        int ans = 0;
        int left = 0;
        while(n>0){
            ans +=n;
            left += n;
            n = left/k;
            left = left%k;
        }
        printf("%d\n",ans);
        scanf("\n");
    }
}