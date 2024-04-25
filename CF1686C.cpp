#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    vector<ll> ans(n+2);
    ll pt = 0;
    for(ll i = 1;i<=n;i+=2){
        ans[i] = v[pt++];
    }
    for(ll i = 2;i<=n;i+= 2){
        ans[i] = v[pt++];
    }
    ans[0] = ans[n];
    ans[n+1] = ans[1];
    for(ll i = 1;i<=n;i++){
        if((ans[i]-ans[i-1])*(ans[i]-ans[i+1])<=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(ll i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)solve();
}
