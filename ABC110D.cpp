#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const ll mxn = 1e5+64;
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
int main(){
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    ll m;
    ll n;
    cin>>n;
    cin>>m;
    map<ll,ll> mp;
    bool flag = true;
    while(flag){
        flag = false;
        for(ll j = 2;j*j<=m;j++){
            if(m%j == 0){
                mp[j]++;
                m/=j;
                flag = true;
                break;
            }
        }
    }
    if(m != 1)mp[m]++;
    ll ans = 1;
    for(auto &i:mp){
        ans = ans*(C(n+i.second-1,n-1))%mod;
    }
    cout<<ans;
}