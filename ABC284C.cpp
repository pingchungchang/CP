#include <bits/stdc++.h>
using namespace std;

const int mxn = 110;
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
    while(m--){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    int ans= 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
}