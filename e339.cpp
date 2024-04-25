#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    scanf("%d",&n);
    ll ans = 0;
    for(int i =0;i<n;i++){
        int k;
        scanf("%d",&k);
        ans+=k;
        printf("%lld",ans);
        if(i != n-1)printf(" ");
    }
}