#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 5050;
const ll mod = 998244353;
ll dp[mxn][mxn][2];
int sz[mxn];
vector<int> tree[mxn];

ll mad(ll a,ll b){
    a += b;
    if(a>=mod) a-= mod;
    return a;
}

void dfs(int now,int par){
    sz[now] = 1;
    dp[now][0][0] = 1;
    dp[now][1][1] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
        for(int i = sz[now];i>=0;i--){
            for(int j = sz[nxt];j>=1;j--){
                if(i+j != 0)dp[now][i+j][0] = mad(dp[now][i+j][0],dp[now][i][0]*dp[nxt][j][0]%mod);
                if(i+j != 0)dp[now][i+j][0] = mad(dp[now][i+j][0],dp[now][i][0]*dp[nxt][j][1]%mod);
                if(i+j != 0)dp[now][i+j][1] = mad(dp[now][i+j][1],dp[now][i][1]*dp[nxt][j][0]%mod);
                if(j>=1&&i>=1)dp[now][i+j-1][1] = mad(dp[now][i+j-1][1],dp[now][i][1]*dp[nxt][j][1]%mod);
            }
        }
        sz[now] += sz[nxt];
        // cout<<now<<' '<<nxt<<':';for(int i = 0;i<20;i++)cout<<dp[now][i][0]<<' ';cout<<endl;cout<<"    ";for(int i = 0;i<20;i++)cout<<dp[now][i][1]<<' ';cout<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    for(int i = 1;i<=n;i++) cout<<mad(dp[1][i][0],dp[1][i][1])<<'\n';
}

/*
i j tar
1 0 i+j
1 1 i+j-1
0 1 i+j
0 0 i+j

*/