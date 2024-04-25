#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[101] = {0};
ll re(int n){
    if(dp[n]==0){
        dp[n] = re(n-1)+re(n-2);
    }
    return dp[n];
}
int main(){
    dp[1] = 1;
    dp[2] = 2;
    ll n;
    while(scanf("%d",&n)!= EOF){
        printf("%lld\n",re(n));
    }
}