#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>> pq;
    ll n,w;
    cin>>n>>w;
    for(int i = 0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        pq.push({a,b});
    }
    ll ans = 0;
    while(!pq.empty()&&w != 0){
        auto now = pq.top();
        pq.pop();
        ll d;
        ans += (d = min(now.second,w))*now.first;
        w -= d;
    }
    cout<<ans;
}