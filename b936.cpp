#include <bits/stdc++.h>
using namespace std;
long long recursive(long long a,long long b){
    if(a<b*2) return 1;
    else{
        return recursive((a+a%2)/2,b)+recursive((a-a%2)/2,b);
    }
}
int main(){
    long long n,m;
    while(scanf("%lld %lld",&n,&m)!=EOF){
        long long ans = recursive(n,m);
        printf("%lld\n",ans);
        scanf("\n");
    }
}