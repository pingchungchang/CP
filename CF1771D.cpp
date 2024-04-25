#include <bits/stdc++.h>
using namespace std;

const int mxn = 2020;
vector<int> paths[mxn];
string val;
int dir[mxn][mxn];
int fa[mxn];
int dp[mxn][mxn];
vector<int> v;

void dfs1(int now,int par){
    dir[now][now] = now;
    fa[now] = par;
    for(int i = 1;i<v.size();i++){
        dir[v[i-1]][now] = v[i];
        dir[now][v[i-1]] = par;
    }
    v.push_back(now);
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        dfs1(nxt,now);
    }
    v.pop_back();
    return;
}
void getans(int a,int b){
    if(!dp[dir[a][b]][b])getans(dir[a][b],b);
    if(!dp[a][dir[b][a]])getans(a,dir[b][a]);
    if(val[a] == val[b])dp[a][b] = dp[dir[a][b]][dir[b][a]]+2;
    dp[a][b] = max({dp[a][b],dp[dir[a][b]][b],dp[a][dir[b][a]]});
    return;
}
void solve(){
    int n;
    cin>>n;
    cin>>val;
    val = "#"+val;
    for(int i =1;i<=n;i++)paths[i].clear();
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=n;j++){
            dp[i][j] = dir[i][j] = 0;
        }
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs1(1,1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(!dir[i][j]){
                dir[i][j] = fa[i];
                dir[j][i] = fa[j];
            }
        }
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++)cout<<dir[i][j]<<' ';cout<<endl;
    // }
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i= 1;i<=n;i++){
        dp[i][i] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(auto nxt:paths[i]){
            if(val[i] == val[nxt])dp[i][nxt] = dp[nxt][i] = 2;
            else dp[i][nxt] = dp[nxt][i] = 1;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(!dp[i][j])getans(i,j);
        }
    }
    // cout<<"HI"<<endl;
    // cout<<"HI"<<endl;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=n;j++)ans = max(ans,dp[i][j]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}