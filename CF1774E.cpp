#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int n,d,m1,m2;
vector<int> paths[mxn];
int par[mxn][32];
int tags[mxn];
void dfs1(int now,int fa){
    par[now][0] = fa;
    for(int i = 1;i<32;i++)par[now][i] = par[par[now][i-1]][i-1];
    for(auto nxt:paths[now]){
        if(nxt == fa)continue;
        dfs1(nxt,now);
    }
    return;
}
int n_par(int now){
    int dd = d;
    for(int i = 0;i<32;i++){
        if((1<<i)&dd)now = par[now][i];
    }
    return now;
}
void dfs2(int now,int fa){
    for(auto nxt:paths[now]){
        if(nxt == fa)continue;
        dfs2(nxt,now);
        tags[now]|=tags[nxt];
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d;
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    fill(par[1],par[1]+32,1);
    dfs1(1,1);
    cin>>m1;
    while(m1--){
        int k;
        cin>>k;
        tags[k]|=1;
        tags[n_par(k)] |=2;
    }
    cin>>m2;
    while(m2--){
        int k;
        cin>>k;
        tags[k] |=2;
        tags[n_par(k)] |= 1;
    }
    dfs2(1,1);
    int total = 0;
    for(int i = 2;i<=n;i++){
        if(tags[i]&1)total++;
        if(tags[i]&2)total++;
    }
    cout<<total*2;
}