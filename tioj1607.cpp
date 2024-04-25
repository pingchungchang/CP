#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e6/2+7;
const ll mod = 1e9+7;

vector<ll> dp(mxn,0LL);


ll pw(ll a,ll b){
    ll now = 1;
    ll p = a;
    while(b != 0){
        if((b&1) == 1)now*= p;
        now%= mod;
        p = (p*p)%mod;
        b>>=1;
    }
    return now;
}
int main(){
    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 2;i<mxn;i++){
        dp[i] = dp[i-1]*(4*i-2);
        dp[i]%= mod;
        ll inverse = pw(i+1,mod-2);
        dp[i] = dp[i]*inverse%mod;
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        ll k;
        cin>>k;
        cout<<dp[k/2]<<'\n';
    }
}
