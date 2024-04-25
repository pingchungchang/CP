#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0;i<n;i++)cin>>arr[i];
    ll dp[n];
    memset(dp,0LL,sizeof(dp));
    for(ll i = n-1;i>=0;i--){
        dp[i] = arr[i];
        if(i+arr[i]<n)dp[i]+= dp[i+arr[i]];
    }
    ll ans = 0;
    for(auto i:dp)ans = max(ans,i);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
