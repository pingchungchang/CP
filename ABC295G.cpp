#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int dsu[mxn];
int sz[mxn];
int ans[mxn];
int dep[mxn],par[mxn];
vector<int> paths[mxn];
int root(int k){
    return k == dsu[k]?k:root(dsu[k]);
}
void onion(int a,int b){
    a = root(a),b= root(b);
    if(sz[a]<sz[b])swap(a,b);
    dsu[b] = a;
    sz[a] += sz[b];
    par[a] = min(par[a],par[b]);
    ans[a] = min(ans[a],ans[b]);
    return;
}

void dfs(int now){
    for(auto nxt:paths[now]){
        dep[nxt] = dep[now]+1;
        dfs(nxt);
    }
    return;
}

void calc(int u,int v){
    v = root(v);
    while(root(u) != root(v)){
        // cout<<u<<' '<<v<<endl;
        u = root(u);
        onion(u,par[u]);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        if(i == 1)par[i] = i;
        else cin>>par[i],paths[par[i]].push_back(i);
        dsu[i] = ans[i] = i;
        sz[i] = 1;
    }
    dfs(1);
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int u,v;
            cin>>u>>v;
            calc(u,v);
        }
        else{
            int v;
            cin>>v;
            cout<<ans[root(v)]<<'\n';
        }
    }
    return 0;
}