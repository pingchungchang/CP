#include <bits/stdc++.h>
using namespace std;

const int mxn= 1e4+10;
vector<int> paths[mxn],inv[mxn];
int deg[mxn],val[mxn],dist[mxn];
bitset<mxn> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>val[i];
    while(m--){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(!deg[i])q.push(i);
        else if(paths[i].empty()){
            paths[i].push_back(n+1);
            deg[n+1]++;
        }
        dist[i] = val[i];
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            deg[nxt]--;
            dist[nxt] = max(dist[nxt],dist[now]+val[nxt]);
            if(!deg[nxt])q.push(nxt);
        }
    }
    // for(int i = 1;i<=n;i++)cout<<dist[i]<<' ';cout<<endl;
    fill(deg,deg+mxn,0);
    for(int i = 1;i<=n+1;i++){
        for(auto nxt:paths[i]){
            deg[i]++;
            inv[nxt].push_back(i);
        }
    }
    q.push(n+1);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:inv[now]){
            if(dist[nxt]+val[now] == dist[now]&&ans[nxt] == false){
                ans[nxt] = true;
                q.push(nxt);
            }
        }
    }
    cout<<ans.count();
}