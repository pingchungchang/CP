#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
const ll mod = 1e9+7;
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

ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}

int main(){
    fac[0] = fac[1] = 1;
    for(ll i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    ll w,h;
    cin>>w>>h;
    cout<<C(w+h-2,h-1)<<'\n';
    return 0;
}