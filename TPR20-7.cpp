#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a[n+1],b[n+1];
    for(ll i = 1;i<=n;i++)cin>>a[i];
    for(ll i = 1;i<=n;i++)cin>>b[i];
    ll v[n];
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>> pq;
    for(ll i = 1;i<=n;i++){
        pq.push(make_pair(b[i]*b[i]-2*b[i]+a[i]*a[i]+5*a[i],i));
    }
    ll ans = 0;
    for(ll i = 1;i<=n;i++){
        ll now = pq.top().second;
        pq.pop();
        ans += (i-1)*(b[now]*b[now]-2*b[now])-(n-i)*(a[now]*a[now]+5*a[now]);
    }
    cout<<ans;
}
