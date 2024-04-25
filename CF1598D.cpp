#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
void solve(){
    ll n;
    cin>>n;
    ll ans = n*(n-1)*(n-2)/6;
    vector<pair<ll,ll>> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
    map<ll,ll> a,b;
    for(auto i:v){
        a[i.fs]++;
        b[i.sc]++;
    }
    for(auto i:v){
        ans -= (a[i.fs]-1)*(b[i.sc]-1);
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
