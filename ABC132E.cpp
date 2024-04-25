#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int dist[mxn][3];
vector<int> paths[mxn];
bool vis[mxn][3];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
    }
    for(auto &i:dist){
        for(auto &j:i)j = mxn*5;
    }
    queue<pii> q;
    int s,e;
    cin>>s>>e;
    vis[s][0] = true;
    dist[s][0] = 0;
    q.push({s,0});
    // cout<<endl;
    while(!q.empty()){
        auto now =q.front();
        q.pop();
        // cout<<now.fs<<' '<<now.sc<<endl;
        int d = now.sc+1;
        if(d>=3)d -= 3;
        for(auto nxt:paths[now.fs]){
            if(vis[nxt][d])continue;
            vis[nxt][d] = true;
            dist[nxt][d] = dist[now.fs][now.sc]+1;
            q.push({nxt,d});
        }
    }
    if(vis[e][0])cout<<dist[e][0]/3;
    else cout<<-1;
}