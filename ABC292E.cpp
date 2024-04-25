#include <bits/stdc++.h>
using namespace std;

const int mxn = 2020;
vector<int> paths[mxn];
bool edges[mxn][mxn];
bitset<mxn> vis;

void dfs(int st,int now){
    vis[now] = true;
    if(st != now)edges[st][now] = true;
    for(auto nxt:paths[now]){
        if(!vis[nxt])dfs(st,nxt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        edges[a][b] = true;
    }
    for(int i = 1;i<=n;i++){
        vis.reset();
        dfs(i,i);
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j)continue;
            cnt += edges[i][j];
        }
    }
    cout<<cnt-m;
}