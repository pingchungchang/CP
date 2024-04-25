#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 5050;
const ll inf = 1e9+10;
ll dp[mxn][mxn][2];
vector<pii> tree[mxn];
ll cost[mxn],dis[mxn];


int dfs(int now){
    dp[now][1][0] = cost[now];
    dp[now][1][1] = cost[now]-dis[now];
    int sz = 1;
    for(auto &i:tree[now])i.fs = dfs(i.sc);
    sort(tree[now].begin(),tree[now].end());
    for(auto ii:tree[now]){
        int ns = ii.fs;
        int nxt = ii.sc;
        sz += ns;
        for(int i = sz;i>=0;i--){
            for(int j = max(0,i+ns-sz);j<min(ns+1,i);j++){
                dp[now][i][0] = min(dp[now][i][0],dp[now][i-j][0]+dp[nxt][j][0]);
                dp[now][i][1] = min(dp[now][i][1],dp[now][i-j][1]+min(dp[nxt][j][0],dp[nxt][j][1]));
            }
            if(i<=ns)dp[now][i][0] = min(dp[now][i][0],dp[nxt][i][0]);
        }
    }
    return sz;
}
int main(){
    ll n,d;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(auto &i:dp)for(auto &j:i)for(auto &k:j)k = inf;
    cin>>n>>d;
    for(int i = 1;i<=n;i++){
        cin>>cost[i]>>dis[i];
        if(i != 1){
            int p;
            cin>>p;
            tree[p].push_back({0,i});
        }
    }
    dfs(1);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(min(dp[1][i][0],dp[1][i][1])<=d)ans = i;
    }
    cout<<ans;
}