#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const ll mxn =  2e6+10;
ll fac[mxn];
ll pw(ll a,ll b){
    ll re= 1;
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

main(){
    fac[0] = 1;
    for(ll i = 1;i<mxn;i++)fac[i] = i*fac[i-1]%mod;
    ll n,m;
    cin>>n>>m;
    cout<<fac[n+m-1]*inv(fac[m])%mod*inv(fac[n-1])%mod;
}