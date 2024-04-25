#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 1e6+10;
ll arr[mxn],dp[mxn][3];
const ll inf = 5e18;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i= 1;i<=n;i++)cin>>arr[i];
    for(auto &i:dp)for(auto &j:i)j = -inf;
    for(int i = 1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = max(dp[i-1][1],0LL)+arr[i];
        dp[i][2] = max(dp[i-1][2]+max(0LL,arr[i]),dp[i-1][0]+arr[i]);
    }
    cout<<dp[n][2];
}