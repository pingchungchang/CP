#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxm = 202;
const int mxn = 101;
int dp[mxm][mxm][mxn];
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(auto &i:dp){
        for(auto &j:i)for(auto &k:j)k = -1;
    }
    int m,n,a,b,c,d;
    cin>>m>>n>>a>>b>>c>>d;
    dp[0][0][0] = 0;
    for(int i = 0;i<m;i++){
        dp[i][0][0] = 0;
        dp[0][i][0] = 0;
        dp[i][0][1] = b*i%d;
        dp[0][i][1] = c*i%d;
        if(i != 0){
            dp[i][0][1] = max(dp[i][0][1],dp[i-1][0][1]);
            dp[0][i][1] = max(dp[0][i][1],dp[0][i-1][1]);
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<m;j++){
            dp[i][j][0] = 0;
            for(int k = 1;k<=n;k++){
                dp[i][j][k] = max({dp[i-1][j-1][k],dp[i-1][j][k],dp[i][j-1][k]});
                if(dp[i-1][j-1][k-1] != -1){
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-1]+(a*(k-1)+b*i+c*j)%d);
                }
            }
        }
    }
    int ans = 0;
    for(auto &i:dp)for(auto &j:i)for(auto &k:j)ans = max(ans,k);
    cout<<ans;
}