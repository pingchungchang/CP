#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    ll big = 0;
    ll ans = 0;
    for(ll i = 1;i<n-1;i++)big = max(big,v[i]);
    if(big == 1||(v.size()==3&&v[1]%2 == 1)){
        cout<<-1<<'\n';
        return;
    }
    for(ll i = 1;i<n-1;i++)ans += (v[i]+1)/2;
    cout<<ans<<'\n';
}
int main(){
    ll t;
    cin>>t;
    for(ll i = 0;i<t;i++)solve();
}
