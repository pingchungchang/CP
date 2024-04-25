#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxn = 2e5+10;
ll arr[mxn],brr[mxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++)cin>>brr[i];
    ll dp[2];
    dp[0] = arr[1],dp[1] = 1e18;
    for(int i = 2;i<=n;i++){
        ll dp2[2];
        dp2[0] = min(dp[0]+brr[i-1],dp[1])+arr[i];
        dp2[1] = min(dp[1]+brr[i-1],dp[0]);
        dp[0] = dp2[0],dp[1] = dp2[1];
    }
    ll ans = min(dp[0]+brr[n],dp[1]);
    // cout<<ans<<endl;
    dp[0] = 1e18,dp[1] = 0;
    for(int i = 2;i<=n;i++){
        ll dp2[2];
        dp2[0] = min(dp[0]+brr[i-1],dp[1])+arr[i];
        dp2[1] = min(dp[1]+brr[i-1],dp[0]);
        dp[0] = dp2[0],dp[1] = dp2[1];
    }
    ans = min({ans,dp[0],dp[1]+brr[n]});
    cout<<ans;
}