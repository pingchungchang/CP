#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
ll n,k,x;
ll dp[mxn][22];
ll arr[mxn];

void solve(){
    cin>>n>>k>>x;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++)arr[i] -= x;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=min(1LL*i,k);j++){
            if(i == j)dp[i][j] = max({dp[i-1][j-1]+x*2+arr[i],arr[i]+x*2});
            else dp[i][j] = max({max(0LL,dp[i-1][j-1])+x*2+arr[i],arr[i]+max(0LL,dp[i-1][j])});
        }
        dp[i][0] = max(dp[i-1][0]+arr[i],arr[i]);
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 0;j<=k;j++)cout<<dp[i][j]<<' ';cout<<endl;
    // }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=min(1LL*i,k);j++){
            if(i+(k-j)>n)continue;
            // cout<<i<<":"<<j<<":"<<dp[i][j]<<endl;
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}