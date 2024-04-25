#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
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

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    fac[0] = 1;
    for(ll i= 1;i<mxn;i++)fac[i] = i*fac[i-1]%mod;
    cin>>n>>k;
    ll ans = 0;
    // cout<<pw(2,3);
    for(ll i = k;i<=n;i++){
        ans += C(n,i)*C(i,k)%mod*pw(2,n-i)%mod;
        // cout<<n<<k<<endl;
    }
    cout<<ans;
}
/*
12+12+3

*/