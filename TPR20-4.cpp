#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m;
    cin>>m;n = 3;
    int v[n+1][m+1];
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>v[i][j];
    ll dp[n+1][m+1];
    memset(dp,0LL,sizeof(dp));
    dp[1][1] = v[1][1];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+v[i][j];
        }
    }
    cout<<dp[n][m];
}

