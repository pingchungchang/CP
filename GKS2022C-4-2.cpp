#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll ans = 1LL;
    while(b != 0){
        if((b&1))ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
ll inverse(ll now){
    return pw(now,mod-2);
}
ll tt = 0;
void solve(){
    tt++;
    ll n;string s;
    cin>>n>>s;
    ll dp[n][n][n];
    memset(dp,0LL,sizeof(dp));

}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}
