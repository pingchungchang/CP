#include <bits/stdc++.h>
using namespace std;

const int mxn = 5050;
int n,m;
void solve(){
    int dp[m+1][2] = {},arr[m+1] = {},hor[m+1] = {},ver[m+1] = {};
    short roll = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        roll ^=1;
        for(int j = 1;j<=m;j++){
            cin>>arr[j];
            if(arr[j] == 0||arr[j] == 1)arr[j] = 1;
            else arr[j] = 0;
            if(arr[j] == 0)dp[j][roll] = hor[j] = ver[j] = 0;
            else{
                dp[j][roll] = 1;
                hor[j] = hor[j-1]+1;
                ver[j]++;
            }
        }
        for(int j= 1;j<=m;j++){
            if(arr[j] == 0)dp[j][roll] = 0;
            else{
                dp[j][roll] = max(dp[j][roll],min({hor[j],dp[j-1][roll^1]+1,ver[j]}));
                ans = max(ans,dp[j][roll]);
            }
        }
        // for(int j = 1;j<=m;j++)cout<<dp[j][roll]<<' ';cout<<'\n';
    }
    cout<<ans*ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        if(!n||!m)return 0;
        solve();
    }
}