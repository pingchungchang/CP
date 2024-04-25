#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    ll dp[m][n+1];
    memset(dp,0,m*n*sizeof(ll));

    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i =1;i<m;i++){
        ll total =0;
        for(int j =1;j<=n;j++){
            dp[i][j] = dp[i-1][j-1];
            total += dp[i][j];
        }
        total += dp[i-1][n];
        dp[i][0] = total;
    }
    ll ans =0;
    for(int i =0;i<=n;i++) ans += dp[m-1][i];
    cout<<ans;
}
