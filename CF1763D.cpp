#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

const ll mxn = 110;
ll fac[mxn];
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
ll mad(ll a,ll b){
    a += b;
    if(a>=b)a -= mod;
    return a;
}
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*fac[a-b]%mod;
}

void solve(){
    ll n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    if(a>b){
        swap(a,b);
        x = n+1-x,y = n+1-y;
        swap(x,y);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    int t;
    cin>>t;
    while(t--)solve();
}