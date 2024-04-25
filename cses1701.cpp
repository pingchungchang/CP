#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int n;
vector<int> tree[mxn];
int dp[mxn];
int sz[mxn];
map<vector<int>,int> mp;
int idx;
vector<int> cens;
void find_sz(int now,int par){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        find_sz(nxt,now);
        sz[now] += sz[nxt];
    }
    return;
}
void find_centroid(int now,int par){
    bool iscen = true;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        if(sz[nxt]>n/2)iscen = false;
        find_centroid(nxt,now);
    }
    if(n-sz[now]>n/2)iscen = false;
    if(iscen)cens.push_back(now);
    assert(cens.size()<=2);
    // assert(cens.size()<=2);
}
void dfs1(int now,int par){
    vector<int> tmp;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs1(nxt,now);
        tmp.push_back(dp[nxt]);
    }
    sort(tmp.begin(),tmp.end());
    if(!mp[tmp]){
        dp[now] = mp[tmp] = ++idx;
    }
    else dp[now] = mp[tmp];
    return;
}
void solve(){
    cin>>n;
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(1,1);
    int tar = dp[1];
    for(int i = 1;i<=n;i++)tree[i].clear();
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[b].push_back(a);
        tree[a].push_back(b);
    }
    dfs1(1,1);
    if(tar != dp[1])cout<<"NO\n";
    else cout<<"YES\n";
    for(int i = 1;i<=n;i++)tree[i].clear();
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}