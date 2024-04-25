#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll dp[n+1][k+1];
    memset(dp,0LL,sizeof(dp));
    dp[0][0] = 1LL;
    for(ll i= 1;i<=n;i++){
        for(ll j = 1;j<=k;j++){
            if(j>k)continue;
            for(ll x = max(0LL,j-m);x<j;x++)dp[i][j]+= dp[i-1][x];
            dp[i][j]%= mod;
        }
    }
    ll total = 0;
    for(ll i = 0;i<=k;i++)total = (total+dp[n][i])%mod;
    cout<<total;
}
