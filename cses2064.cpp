#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e6+10;
ll fac[mxn];
const ll mod = 1e9+7;

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

main(){
    fac[0] = 1;
    for(ll i = 1;i<mxn;i++)fac[i] = i*fac[i-1]%mod;
    int n;
    cin>>n;
    if(n&1)cout<<0;
    else cout<<(C(n,n>>1)+mod-C(n,1+(n>>1)))%mod;
}