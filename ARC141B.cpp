#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
ll highbit(ll now){
    ll ans = 0;
    while(now != 0){
        ans++;
        now>>=1;
    }
    return 1LL<<(ans-1);
}
int main(){
    ll n,m;
    cin>>n>>m;
    if((n-1)>60||(1LL<<(n-1))>highbit(m)){
        cout<<0;
        return 0;
    }
    ll dp[66];
    memset(dp,0LL,sizeof(dp));
    dp[0] = 1LL;
    dp[1] = 1LL;
    ll h = highbit(m);
    for(ll i = 1;(1LL<<i)<h;i++){
        for(ll j = 64;j>=1;j--){
            dp[j] += ((1LL<<i))%mod*dp[j-1]%mod;
            dp[j] %= mod;
        }
    }
    if(m == 1){
        cout<<dp[n];
        return 0;
    }
    for(ll j = 64;j>=1;j--){
        dp[j] += ((m^h)+1)%mod*dp[j-1]%mod;
        dp[j] %= mod;
    }
    cout<<dp[n];

}
