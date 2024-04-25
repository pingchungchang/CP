#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return re;
}

const ll mxn = 2e5+10;
ll dp[mxn];
int main(){
    ll n,p;
    cin>>n>>p;
    ll pa = p*pw(100,mod-2)%mod,pb = (100-p)*pw(100,mod-2)%mod;
    dp[1] = 1;
    for(int i = 2;i<=n;i++){
        dp[i] = 1+(pa*dp[i-2]%mod+pb*dp[i-1]%mod);
        if(dp[i]>=mod)dp[i] -= mod;
    }
    cout<<dp[n];
}