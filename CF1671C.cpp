#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll d = 0;
    ll n,x;
    cin>>n>>x;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        sum += k;
        pq.push(k);
    }
    ll ans = 0;
    while(!pq.empty()){
        while(!pq.empty()&&sum+d*pq.size()>x){
            sum -= pq.top();
            pq.pop();
        }
        if(pq.empty())break;
        ll delta = (x-sum-d*pq.size())/pq.size()+1;
        d += delta;
        ans += delta*pq.size();
        sum -= pq.top();
        pq.pop();
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
