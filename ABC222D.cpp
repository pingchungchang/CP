#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(ll i =0;i<n;i++)cin>>a[i];
    for(ll i =0;i<n;i++)cin>>b[i];
    ll dp[b[n-1]+1];
    ll s = b[n-1];
    memset(dp,0,(b[n-1]+1)*sizeof(ll));
    dp[a[0]] = 1;
    for(ll i = a[0]+1;i<=s;i++){
        dp[i] = dp[i-1];
        if(i<=b[0])dp[i]++;
    }
    for(ll i =1;i<n;i++){
        for(ll j = a[i]+1;j<=s;j++){
            if(j<=b[i])dp[j]+= dp[j-1];
            else dp[j] = dp[j-1];
            dp[j] = dp[j]%mod;
        }
    }
    cout<<dp[s];
}
