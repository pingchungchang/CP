#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    while(scanf("%d %d",&n,&m)){
        if(m == n&&n==0)return 0;
        long long k = max(n,m);
        n = min(n,m);
        m = k;
        k = m-n;
        long long ans = 0;
        ans=n*(n+1)*(2*n+1)/6+ k*n*(n+1)/2;
        printf("%lld\n",ans);
        scanf("\n");
    }
}