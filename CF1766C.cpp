#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string arr[2];
    for(auto &i:arr)cin>>i;
    int dp[2][n];
    memset(dp,0,sizeof(dp));
    if(arr[0][0] == 'B')dp[0][0] = 1;
    if(arr[1][0] == 'B')dp[1][0] = 1;
    for(int i = 1;i<n;i++){
        // cout<<arr[0][i]<<arr[1][i]<<",";
        if(arr[0][i] == 'B'&&arr[1][i] == 'B'){
            dp[0][i] = dp[1][i-1];
            dp[1][i] = dp[0][i-1];
        }
        else{
            if(arr[0][i] == 'B')dp[0][i] = dp[0][i-1];
            if(arr[1][i] == 'B')dp[1][i] = dp[1][i-1];
        }
    }
    // for(int i = 0;i<2;i++){
    //     for(auto &j:dp[i])cout<<j<<' ';
    //     cout<<'\n';
    // }
    if(dp[0][n-1]||dp[1][n-1])cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}