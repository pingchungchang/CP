#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 303;
const ll shift = mxn*mxn;

ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}
ll dp[mxn][mxn*mxn*2];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    dp[2][arr[2]+shift] = 1;
    for(int i = 2;i<n;i++){
        for(int j = 0;j<shift*2;j++){
            if(!dp[i][j])continue;
            int v = j-shift;
            dp[i+1][arr[i+1]-v+shift] = mad(dp[i+1][arr[i+1]-v+shift],dp[i][j]);
            if(v == 0)continue;
            dp[i+1][arr[i+1]+v+shift] = mad(dp[i+1][arr[i+1]+v+shift],dp[i][j]);
        }
    }
    ll ans = 0;
    for(auto &i:dp[n])ans = mad(ans,i);
    cout<<ans;
}