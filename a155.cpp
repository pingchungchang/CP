#include <bits/stdc++.h>
using namespace std;


int n,m;
int t = 0;
void solve(){
    t++;
    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<int>a(n),b(m);
    for(int i = 0;i<n;i++)cin>>a[i];for(int i = 0;i<m;i++)cin>>b[i];
    if(a[0] == b[0])dp[0][0] = 1;
    for(int i = 1;i<n;i++){
        dp[i][0] = dp[i-1][0];
        if(a[i] == b[0])dp[i][0] = 1;
    }
    for(int i = 1;i<m;i++){
        dp[0][i] = dp[0][i-1];
        if(a[0] == b[i])dp[0][i] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<"Twin Towers #"<<t<<"\nNumber of Tiles : "<<dp[n-1][m-1]<<"\n\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        if(n == 0&&m == 0)return 0;
        solve();
    }
}
