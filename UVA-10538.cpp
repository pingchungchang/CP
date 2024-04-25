#include <stdio.h>
using namespace std;
int findroot(int a,int arr[]){
    while(arr[a]!=0&&arr[a]!=a){
        a = arr[a];
    }
    return a;
}
int main(){
    int n,m;
    int times = 0;
    while(scanf("%d %d",&n,&m) != EOF){
        times++;
        if(n == m&&m==0)return 0;
        int arr[n+1] = {0};
        for(int i =0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            arr[findroot(a,arr)] = findroot(b,arr);
        }
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(arr[i] == 0||arr[i] == i)ans++;
        }
        printf("Case %d: %d\n",times,ans);
    }
}