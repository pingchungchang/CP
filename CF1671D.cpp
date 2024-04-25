#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    ll ans = 0;
    ll a1 = v[0]-1,a2 = x-v[0];
    ll big = v[0],small = v[0];
    for(ll i = 1;i<n;i++){
        big = max(big,v[i]);
        small = min(small,v[i]);
        ans += abs(v[i]-v[i-1]);
        a1 = min(a1,min(v[i],v[i-1])*2-2);
        a2 = min(a2,x*2-max(v[i],v[i-1])*2);
    }
    a1 = min(a1,v[n-1]-1);
    a2 = min(a2,x-v[n-1]);
    if(a1>0)ans+= a1;
    if(a2>0)ans += a2;
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
