#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
const int mxn = 2e5+10;
vector<int> paths[mxn];
bitset<mxn> vis;
int my[mxn];
int n,m,k;

int dfs(int now){
    if(vis[now])return false;
    vis[now] = true;
    for(auto &i:paths[now]){
        if(!my[i]){
            my[i] = now;
            return true;
        }
        else if(dfs(my[i])){
            my[i] = now;
            return true;
        }
    }
    return false;
}
void solve(){
    cin>>n>>m>>k;
    for(auto &i:paths)i.clear();
    while(k--){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b+n);
    }
    memset(my,0,sizeof(my));
    int ans = 0;
    for(int i = 1;i<=n;i++){
        vis.reset();
        ans += dfs(i);
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}