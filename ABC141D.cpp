#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        pq.push(k);
    }
    while(!pq.empty()&&m--){
        ll now = pq.top();
        pq.pop();
        now/=2;
        pq.push(now);
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
}
