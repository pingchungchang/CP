#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll inf = 1e18;
vector<pll> paths[mxn];
ll dist[mxn];
int deg[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    fill(dist,dist+n+1,inf);
    dist[0] = 0;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        paths[a].push_back({b,c});
        deg[b]++;
    }
    queue<ll> q;
    dist[1] = 0;
    for(int i = 1;i<=n;i++){
        if(!deg[i]){
            dist[i]  =0;
            q.push(i);
        }
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            deg[nxt.fs]--;
            dist[nxt.fs] = min(dist[nxt.fs],dist[now]+nxt.sc);
            if(!deg[nxt.fs])q.push(nxt.fs);
        }
    }
    ll total = 0;
    for(int i =1;i<=n;i++)total += dist[i];
    cout<<total;
}
