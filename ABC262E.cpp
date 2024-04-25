#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1) re = re*a%mod;
         a= a*a%mod;
         b>>=1;
    }
    return re;
}
ll inv(ll k){return pw(k,mod-2);}
const ll mxn = 2e5+10;
ll fac[mxn];
ll C(ll a,ll b){
    if(b>a)return 0LL;
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}
int deg[mxn];
int main(){
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    int n,m;
    int k;
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    int odd = 0,ev = 0;
    for(int i = 1;i<=n;i++){
        if(deg[i]&1)odd++;
        else ev++;
    }
    ll ans= 0;
    for(int i = 0;i<=min(odd,k);i+=2){
        ans = mad(ans,C(odd,i)*C(ev,k-i)%mod);
    }
    cout<<ans;
}