#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const ll mxn = 2020;

ll fac[mxn];

ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}

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
    ios::sync_with_stdio(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(int i= 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    ll n,k;
    cin>>n>>k;
    ll x = n-k;
    for(int i = 1;i<=k;i++){
        if(i>x+1){
            cout<<0<<'\n';continue;
        }
        cout<<C(x+1,i)*C(k-i+i-1,i-1)%mod<<'\n';
    }
    return 0;
}
/*
H(a,b) = C(a+b-1,b-1)

*/