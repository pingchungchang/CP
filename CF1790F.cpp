#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> tree[mxn];
int centree[mxn],dp[mxn];
int anc[mxn][32];
int sz[mxn],dep[mxn],del[mxn];
int ans;
void szdfs(int now,int par){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par||del[nxt])continue;
        dep[nxt] = dep[now]+1;
        szdfs(nxt,now);
        sz[now] += sz[nxt];
    }
    return;
}
int find_centroid(int now,int par,int tar){
    for(auto nxt:tree[now]){
        if(nxt == par||del[nxt])continue;
        if(sz[nxt]>=tar)return find_centroid(nxt,now,tar);
    }
    return now;
}
void cendfs(int now,int par){
    dep[now] = 1;
    szdfs(now,now);
    auto cen = find_centroid(now,now,sz[now]/2);
    centree[cen] = par;
    del[cen] = true;
    for(auto nxt:tree[cen]){
        if(del[nxt])continue;
        cendfs(nxt,cen);
    }
    return;
}
void dfs(int now,int par){
    dep[now] = dep[par]+1;
    anc[now][0] = par;
    for(int i = 1;i<32;i++)anc[now][i] = anc[anc[now][i-1]][i-1];
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
    }
    return;
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    int d= dep[a]-dep[b];
    for(int i = 31;i>=0;i--){
        if((1<<i)&d)a = anc[a][i];
    }
    for(int i = 31;i>=0;i--){
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i],b = anc[b][i];
        }
    }
    if(a != b)a = anc[a][0];
    return a;
}
void add(int now){
    for(int p = now;p;p = centree[p]){
        // cout<<p<<endl;
        int d = dep[now]+dep[p]-dep[lca(now,p)]*2;
        ans = min(ans,dp[p]+d);
        dp[p] = min(dp[p],d);
    }
    return;
}
void solve(){
    int n;
    cin>>n;
    int c0;
    cin>>c0;
    for(int i = 1;i<=n;i++)tree[i].clear();
    fill(centree,centree+n+1,0);
    for(int i = 1;i<=n;i++)dp[i] = mxn;
    fill(del,del+n+1,0);
    for(int i = 1;i<=n;i++)fill(anc[i],anc[i]+32,0);
    int arr[n-1];
    for(auto &i:arr)cin>>i;
    ans = mxn;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cendfs(1,0);
    dep[1] = 0;
    dfs(1,1);
    // for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
    add(c0);
    // cout<<"HI"<<endl;return;
    for(auto &i:arr){
        // for(int j = 1;j<=n;j++)cout<<dp[j]<<' ';cout<<ans;cout<<endl;
        // cout<<dep[2]+dep[6]-2*dep[lca(2,6)]<<endl;
        add(i);
        cout<<ans<<' ';
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}