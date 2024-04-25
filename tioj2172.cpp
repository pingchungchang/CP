#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
const int mxn = 1e5+10;
vector<int> tree[mxn];
const int bits = 24;
int par[mxn][bits];
int dep[mxn];
void dfs(int now){
    for(int i = 1;i<bits;i++)par[now][i] = par[par[now][i-1]][i-1];
    for(auto nxt:tree[now]){
        if(nxt == par[now][0])continue;
        //cout<<now<<','<<nxt<<' '<<par[now][0]<<endl;
        dep[nxt] = dep[now]+1;
        par[nxt][0] = now;
        dfs(nxt);
    }
    return;
}
int lca(int a,int b){
    if(dep[b]>dep[a])swap(a,b);
    int dif = dep[a]-dep[b];
    for(int i = bits-1;i>=0;i--){
        if((1<<i)&dif){
            a = par[a][i];
        }
    }
    for(int i = bits-1;i>=0;i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return (a == b?a:par[a][0]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    /*
    for(int i = 0;i<n;i++){
        cout<<i<<":";
        for(auto nxt:tree[i])cout<<nxt<<',';cout<<endl;
    }
    */
    par[0][0] = 0;
    dfs(0);
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<dep[a]+dep[b]-2*dep[lca(a,b)]<<'\n';
    }
    return 0;
}
