#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mx = 1e18;
vector<ll> v;

bool f(ll now,ll tar){
    ll o = 0,t = 0;
    for(auto i:v){
        t += (tar-i)/2;
        if((tar-i)%2 == 1)o++;
    }
    if(o<=(now+1)/2&&now/2*3+now%2>=o+t*2)return true;
    else return false;
}
void solve(){
    ll n;
    cin>>n;
    v = vector<ll>(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    ll ans = INT_MAX;
    sort(v.begin(),v.end());
    ll l = 0,r = mx;
    while(l != r){
        ll mid = (l+r)/2;
        if(f(mid,v.back()))r = mid;
        else l = mid+1;
    }
    ans = l;
    l = 0,r = mx;
    while(l != r){
        ll mid = (l+r)/2;
        if(f(mid,v.back()+1))r = mid;
        else l = mid+1;
    }
    ans = min(ans,l);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
