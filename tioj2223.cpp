#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e5+10;
ll dp[mxn]; 
#define pll pair<ll,ll>
#define fs first
#define sc second
vector<pll> v;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    while(n--){
        ll w,p;
        cin>>w>>p;
        while(w--)pq.push(p);
    }
    ll ans = 0;
    while(!pq.empty()&&m--){
        ans += pq.top();pq.pop();
    }
    cout<<ans;
}