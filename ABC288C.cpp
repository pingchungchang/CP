#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
bitset<mxn> vis;
int ans =0;
void dfs(int now,int par = 0){
    vis[now] = true;
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        if(vis[nxt]){
            // cout<<now<<' '<<nxt<<endl;
            ans++;
        }
        else{
            dfs(nxt,now);
        }
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
        paths[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    cout<<ans/2;
}