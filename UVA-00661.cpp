#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c,times = 0;
    while(scanf("%d %d %d",&n,&m,&c) != EOF){
        times++;
        if(n==m&&m==c&&n==c&&n==0)return 0;
        if(times !=1)printf("\n\n");
        int arr[n+1];
        for(int i = 0;i<n;i++){
            int k;
            scanf("%d",&k);
            arr[i+1] = k;
        }
        int biggest = 0;
        int ans = 0;
        for(int i =0;i<m;i++){
            int k;
            scanf("%d",&k);
            ans += arr[k];
            arr[k] = -arr[k];
            biggest = max(ans,biggest);
        }
        printf("Sequence %d\n",times);
        if(biggest>c)printf("Fuse was blown.");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.",biggest);
    }
}