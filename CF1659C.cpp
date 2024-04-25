#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> v(n+1);
    for(ll i = 1;i<=n;i++)cin>>v[i];
    vector<ll> pre(n+1,0LL);
    for(ll i = 1;i<=n;i++)pre[i] = pre[i-1]+v[i];
    ll ans = LONG_LONG_MAX;
    for(ll i = 0;i<n;i++){
        ll tmp = a*v[i]+(pre[n]-pre[i]-(n-i)*v[i])*b+v[i]*b;
        ans = min(ans,tmp);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
