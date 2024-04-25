#include <bits/stdc++.h>
using namespace std;


const int mxn = 2e5+10;
set<int> colors[mxn];
vector<int> childs[mxn];
int par[mxn] = {};
int val[mxn];
int n;
int ans[mxn];
void com(int a,int b){
    if(colors[a].size()<colors[b].size())swap(colors[a],colors[b]);
    for(auto now:colors[b])colors[a].insert(now);
    return;
}
void dfs(int now){
    for(auto nxt:childs[now]){
        if(nxt == par[now])continue;
        par[nxt] = now;
        dfs(nxt);
        com(now,nxt);
    }
    ans[now] = colors[now].size();
    return;
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>val[i];
        colors[i].insert(val[i]);
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        childs[a].push_back(b);
        childs[b].push_back(a);
    }
    dfs(1);
    for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}
