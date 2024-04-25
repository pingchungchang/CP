#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
#define ll long long
const ll mod = 998244353;
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
const ll mxn = 1e6+10;
ll fac[mxn];
vector<ll> a1(mxn),a2(mxn),re;

void solve(){
    ll n;
    cin>>n;
    if(n == 2){
        cout<<1<<'\n';
        return;
    }
    cout<<fac[n]*fac[n-3]%mod*re[n]%mod<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++){
        fac[i] = fac[i-1]*i%mod;
    }
    for(ll i = 1;i<mxn;i++){
        if(i != 1)a1[i] = inv(fac[i-2])%mod*inv(fac[i]);
        a2[i] = inv(fac[i-1])%mod*inv(fac[i])%mod*(i+1)%mod;
    }
    re = convolution(a1,a2);
    ll t;
    cin>>t;
    while(t--)solve();
}