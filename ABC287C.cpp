#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
bitset<mxn> vis;
void dfs(int now){
    vis[now] = true;
    for(auto nxt:paths[now]){
        if(!vis[nxt])dfs(nxt);
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    int cnt[3] = {};
    for(int i = 1;i<=n;i++){
        if(paths[i].size()>2||paths[i].empty()){
            cout<<"No";
            return 0;
        }
        cnt[paths[i].size()]++;
    }
    dfs(1);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            cout<<"No";
            return 0;
        }
    }
    if(m != n-1)cout<<"No";
    else{
        if(cnt[1]!= 2||cnt[2] != n-2)cout<<"No";
        else cout<<"Yes";
    }
}