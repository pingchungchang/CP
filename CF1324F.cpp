#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
int col[mxn],dp[mxn],ans[mxn];

void dfs1(int now,int par){
    dp[now] = 0;
    for(auto &nxt:paths[now]){
        if(nxt == par)continue;
        dfs1(nxt,now);
        dp[now] = max(dp[now],dp[now]+dp[nxt]);
    }
    dp[now] += col[now];
    return;
}
void dfs2(int now,int par){
    if(now != par){
        if(dp[now]<0)dp[now] += max(dp[par],0);
        else dp[now] += max(0,dp[par]-dp[now]);
    }
    ans[now] = dp[now];
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        dfs2(nxt,now);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>col[i];
        if(!col[i])col[i] = -1;
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}