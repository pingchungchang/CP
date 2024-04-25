#include <bits/stdc++.h>
using namespace std;


const int mxn = 1010;
int dp[mxn][mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ans = -2e9;
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>dp[i][j];
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],0})+dp[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        ans= max(ans,dp[i][m]);
    }
    for(int i = 1;i<=m;i++){
        ans = max(ans,dp[n][i]);
    }
    cout<<ans;
}
