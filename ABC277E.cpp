#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int inf = 1e9;
const int mxn = 2e5+10;
bitset<mxn> vis[2];
bitset<mxn> change;
vector<pii> paths[mxn];
int dist[2][mxn];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(auto &i:dist)for(auto &j:i)j= inf;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    for(int i = 0;i<k;i++){
        int t;
        cin>>t;
        change[t] = true;
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    pq.push({0,{1,1}});
    dist[1][1] = 0;
    while(!pq.empty()){
        auto ttt = pq.top();
        pq.pop();
        auto now= ttt.sc;
        vis[now.sc][now.fs] = true;
        for(auto nxt:paths[now.fs]){
            if(nxt.sc == now.sc){
                if(!vis[now.sc][nxt.fs]&&dist[nxt.sc][nxt.fs]>dist[nxt.sc][now.fs]+1){
                    dist[now.sc][nxt.fs] = dist[now.sc][now.fs]+1;
                    pq.push({dist[now.sc][nxt.fs],{nxt.fs,now.sc}});
                }
            }
        }
        if(change[now.fs]&&!vis[now.sc^1][now.fs]){
            dist[now.sc^1][now.fs] = dist[now.sc][now.fs];
            pq.push({dist[now.sc^1][now.fs],{now.fs,now.sc^1}});
        }
    }
    if(min(dist[0][n],dist[1][n]) == inf)cout<<-1;
    else cout<<min(dist[0][n],dist[1][n]);
}
