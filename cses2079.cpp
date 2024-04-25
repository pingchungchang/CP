#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;

int par[mxn];
int sz[mxn];
int n;
int cen = -1;
vector<int> childs[mxn];
void dfs(int now){
    sz[now] = 1;
    bool flag = true;
    for(auto nxt:childs[now]){
        if(nxt == par[now])continue;
        par[nxt] = now;
        dfs(nxt);
        sz[now] += sz[nxt];
        if(sz[nxt]>n/2)flag = false;
    }
    if(flag == true && n-sz[now]<=n/2)cen = now;
    return;
}
int main(){
    cin>>n;
    for(int i = 1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        childs[a].push_back(b);
        childs[b].push_back(a);
    }
    dfs(1);
    cout<<cen;
    return 0;
}
