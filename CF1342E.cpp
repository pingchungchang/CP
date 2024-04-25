#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 998244353;
ll pw(ll a,ll b){
    a%=mod;
    ll now = 1LL;
    while(b != 0){
        if((b&1))now = now*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return now;
}
ll inverse(ll k){
    return pw(k,mod-2);
}
ll c(ll a,ll b){
    ll ans = 1LL;
    for(ll i = a;i>=a-b+1;i--)ans = ans*i%mod;
    for(ll i = 1;i<=b;i++)ans = ans*inverse(i)%mod;
    return ans;
}
int main(){
    ll n,m;
    cin>>n>>m;
    if(m>=n){
        cout<<0;
        return 0;
    }
    else if(m == 0){
        ll tmp = 1LL;
        for(ll i = 1;i<=n;i++)tmp = tmp*i%mod;
        cout<<tmp;
        return 0;
    }
    ll k = n-m;
    ll now = 0;
    ll ans = 0;
    ll C = 1LL;
    while(now != k+1){
        //cout<<k<<' '<<now<<' '<<C<<endl;
        ans += (now%2 == 0?1LL:-1LL)*pw(k-now,n)*C%mod;
        ans = (ans+mod)%mod;
        C = C*(k-now)%mod*inverse(now+1)%mod;
        now++;
        ans %= mod;
    }
    //cout<<ans<<endl;
    ans = ans*(c(n,k))%mod;
    cout<<ans*2%mod;
    return 0;
}
