#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define int ll
#define ll long long
const int mxn = 2020;
const int inf = 1e9;
bool roll = false;
int dp[2][mxn];
int arr[mxn];

main(){
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(auto &i:dp[roll])i = -inf;
    dp[roll][0] = 0;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        roll^=1;
        for(auto &j:dp[roll])j = -inf;
        for(int j = 0;j<h;j++){
            if(l<=j&&j<=r)dp[roll][j] = max(dp[roll][j],dp[roll^1][(j+h-arr[i])%h]+1);
            else dp[roll][j] = max(dp[roll][j],dp[roll^1][(j+h-arr[i])%h]);
            arr[i] = (arr[i]+h-1)%h;
            if(l<=j&&j<=r)dp[roll][j] = max(dp[roll][j],dp[roll^1][(j+h-arr[i])%h]+1);
            else dp[roll][j] = max(dp[roll][j],dp[roll^1][(j+h-arr[i])%h]);
            arr[i] = (arr[i]+1)%h;
        }
        // for(int j = 0;j<h;j++)cout<<dp[roll][j]<<' ';cout<<endl;
    }
    cout<<*max_element(dp[roll],dp[roll]+mxn);
}