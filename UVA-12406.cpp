#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp(18,{-1,1,1});
ll findans(ll q){
    if(dp[q][0] == -1){
        findans(q-1);
        ll x = 2*dp[q-1][1]+dp[q-1][0];
        if(x%dp[q][2] == 0){
            dp[q][0] = x;
        }
        else{
            dp[q][0] = dp[q-1][1]+dp[q-1][0];
        }
    }
    return dp[q][0];
}
int main(){
    dp[0][0] = 0;
    dp[1][0] = 2;
    for(int i =1;i<18;i++){
        dp[i][1]= 10*dp[i-1][1];
        dp[i][2] = 2*dp[i-1][2];
    }
    ll p,q;
    int n;
    scanf("%d",&n);
    for(int a = 0;a<n;a++){
        printf("Case %d: ",a+1);
        scanf("%lld %lld",&p,&q);
        ll k = findans(min(p,q));
        if(k % dp[q][2] == 0){
            if(p>q){
                for(ll i =0;i<p-q;i++){
                    printf("%d",1);
                }
                printf("%lld ",k);
                for(ll i =0;i<p-q;i++){
                    printf("%d",2);
                }
                printf("%lld\n",k);
            }
            else printf("%lld\n",k);
        }
        else printf("impossible\n");
    }
}