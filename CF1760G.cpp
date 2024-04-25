#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<pii> tree[mxn];
int n,a,b;
int d1[mxn],d2[mxn];
void dfs1(int now,int par){
    for(auto nxt:tree[now]){
        if(nxt.fs == par||nxt.fs == b)continue;
        d1[nxt.fs] = d1[now]^nxt.sc;
        dfs1(nxt.fs,now);
    }
    return;
}
void dfs2(int now,int par){
    for(auto nxt:tree[now]){
        if(nxt.fs == par)continue;
        d2[nxt.fs] = d2[now]^nxt.sc;
        dfs2(nxt.fs,now);
    }
    return;
}
void solve(){
    cin>>n>>a>>b;
    for(int i =1;i<=n;i++)tree[i].clear();
    fill(d1,d1+n+1,-1);fill(d2,d2+n+1,-1);
    d1[a] = 0;
    d2[b] = 0;
    for(int i = 0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    dfs1(a,a);
    dfs2(b,b);
    set<int> st;
    d2[b] = -1;
    for(int i = 1;i<=n;i++){
        if(d2[i] != -1)st.insert(d2[i]);
    }
    for(int i =1;i<=n;i++){
        if(st.find(d1[i]) != st.end()){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}