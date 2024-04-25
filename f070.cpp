#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    int x = a;
    int pro = a*b;
    a = max(a,b);
    b = min(x,b);
    while(b!=0){
        a -= (a/b)*b;
        int j = a;
        a = b;
        b = j;
    }
    return pro/a;
}
int main(){
    pair<int,int> k[3];
    for(int i=0;i<3;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        k[i].first = a;
        k[i].second = b;
    }
    int arr[3];
    arr[0] = lcm(k[1].first,k[2].first);
    arr[1] = lcm(k[0].first,k[2].first);
    arr[2] = lcm(k[0].first,k[1].first);
    int ans = 0;
    for(int i =0;i<3;i++){
        while(ans%k[i].first!=k[i].second){
            ans += arr[i];
        }
    }
    int x = lcm(arr[0],k[0].first);
    ans = ans%x;
    printf("%d",ans);
}