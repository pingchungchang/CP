#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
int main(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    ll n,m,g;
    cin>>n>>m>>g;
    for(ll i = 0;i<n;i++){
        pll p;
        cin>>p.fs>>p.sc;
        pq.push(p);
    }
    ll ans = 0LL;
    while(pq.top().fs<g){
        ans++;
        vector<pll> tmp;
        for(ll i = 0;i<m;i++){
            tmp.push_back(pq.top());
            pq.pop();
        }
        for(auto i:tmp){
            pq.push(make_pair(i.fs+i.sc,i.sc));
        }
    }
    cout<<ans;
}
