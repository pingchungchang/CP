#include <bits/stdc++.h>
using namespace std;

const int mxn = 303;
vector<int> tree[mxn];
int dp[mxn][mxn];
int sz[mxn];

void dfs(int now,int par){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
        sz[now] += sz[nxt];
        for(int i = sz[now];i>=2;i--){
            for(int j = 0;j<=min(i-1,sz[nxt]);j++){
                dp[now][i] = max(dp[now][i],dp[now][i-j]+dp[nxt][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int k,s;
        cin>>k>>s;
        for(int j = 1;j<=m;j++)dp[i][j] = s;
        tree[k].push_back(i);
    }
    dfs(0,0);
    cout<<dp[0][m+1];
}