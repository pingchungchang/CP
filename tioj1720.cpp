#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>vv;
ll ans = 0;

void f(ll l,ll r){
    if(l == r)return;
    else if(l == r-1){
        if(vv[l]>vv[r]){
            swap(vv[l],vv[r]);
            ans++;
        }
        return;
    }
    ll mid = (l+r)/2;
    f(l,mid);
    f(mid+1,r);
    ll p2 = mid+1;
    vector<ll> vvv;
    for(ll i = l;i<=mid;i++){
        while(p2 != r+1&&vv[p2]<vv[i]){
            vvv.push_back(vv[p2]);
            p2++;
        }
        ans += p2-mid-1;
        vvv.push_back(vv[i]);
    }
    while(p2 != r+1)vvv.push_back(vv[p2++]);
    for(ll i = l;i<=r;i++)vv[i] = vvv[i-l];
    return;

}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i].first;
    for(ll i = 0;i<n;i++)cin>>v[i].second;
    sort(v.begin(),v.end());
    vv = vector<ll>(n);
    for(ll i = 0;i<n;i++)vv[i] = v[i].second;
    f(0,n-1);
    cout<<ans;
}
