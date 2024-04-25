#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((ll)1e9+7)
int main(){
    ll n,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    cin>>n>>k;
    ll arr[n];
    for(ll i =0;i<n;i++)cin>>arr[i];
    ll dp[2][k+1];
    for(ll i =0;i<=arr[0];i++){
        dp[0][i] = 1;
        if(i !=0)dp[0][i]+= dp[0][i-1];
    }
    for(ll i =arr[0]+1;i<=k;i++)dp[0][i] = dp[0][arr[0]];
    //for(ll i =0;i<=k;i++)dp[0][i] = dp[0][i];
    //cout<<endl;
    for(ll i =1;i<n;i++){
        dp[1][0] =1;
        for(ll j =1;j<=k;j++){
            if(j>=arr[i]+1) dp[1][j] =dp[1][j-1]+ dp[0][j]-dp[0][j-arr[i]-1]+mod;
            else dp[1][j] = dp[0][j]+dp[1][j-1];
            dp[1][j] = dp[1][j]%mod;
        }
        for(ll j =0;j<=k;j++)dp[0][j] = dp[1][j];
    }
    if(k==0)cout<<1;
    else cout<<(dp[0][k]-dp[0][k-1]+mod)%mod;
}
