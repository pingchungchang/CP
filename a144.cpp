#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>dp[i][j];
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int ans= dp[1][1];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = i;k<=n;k++){
                for(int l = j;l<=n;l++){
                    ans = max(ans,dp[k][l]-dp[i-1][l]-dp[k][j-1]+dp[i-1][j-1]);
                }
            }
        }
    }
    cout<<ans;
}
