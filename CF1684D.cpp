#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        ans += v[i];
        v[i] += i;
    }
    ans += (n-1)*k;
    sort(v.rbegin(),v.rend());
    for(ll i = 0;i<k;i++)ans -= v[i];
    ans -= k*(k-1)/2;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)solve();
}
