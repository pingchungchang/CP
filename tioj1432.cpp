#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,w;
vector<ll> v;
bool f(ll val){
    ll t = 0;
    ll now = 0;
    for(ll i = 0;i<n;i++){
        now += v[i];
        if(now>val){
            t++;
            now  = v[i];
        }
        if(v[i]>val)return false;
    }
    if(t>w)return false;
    else return true;
}
void solve(){
    ll l = 0,r = INT_MAX;
    v = vector<ll>(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    while(l != r){
        ll mid = (l+r)>>1;
        if(f(mid))r = mid;
        else l = mid+1;
    }
    cout<<l<<'\n';
    return;
}
int main(){
    while(cin>>n>>w){
        if(n == 0&&w == 0)return 0;
        solve();
    }
}
