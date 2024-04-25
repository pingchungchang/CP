#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 1e6+10;

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
ll fac[mxn];
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
void solve(){
    ll l,r;
    cin>>l>>r;
    ll cnt = 1,mul = 1;
    ll now = l;
    while(now*2<=r){
        now *=2;
        cnt++;
        mul *=2;
    }
    ll ans = r/mul-l+1;
    if(mul != 1){
        mul = mul/2*3;
    }
    ans += (cnt-1)*max(0LL,r/mul-l+1)%mod;
    cout<<cnt<<' '<<ans%mod<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(ll i = 2;i<mxn;i++){
        fac[i] = fac[i-1]*i%mod;
    }
    int t;
    cin>>t;
    while(t--)solve();
}