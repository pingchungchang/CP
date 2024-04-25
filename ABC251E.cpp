#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    vector<pair<ll,ll>> dp(n+1,make_pair(0,0));
    dp[0] = make_pair(v[0],v[0]);
    for(ll i = 1;i<n;i++){
        dp[i].sc = min(dp[i-1].fs,dp[i-1].sc)+v[i];
        dp[i].fs = min(dp[i-1].sc,dp[i].sc);
    }
    //cout<<dp[n-1].fs<<' '<<dp[n-1].sc<<endl;
    ll ans = min(dp[n-1].fs,dp[n-1].sc);
    dp = vector<pair<ll,ll>>(n+1,make_pair(0,0));
    dp[0] = make_pair(v[n-1],v[n-1]);
    for(ll i = 1;i<n;i++){
        dp[i].sc = min(dp[i-1].fs,dp[i-1].sc)+v[i-1];
        dp[i].fs = min(dp[i-1].sc,dp[i].sc);
    }
    //cout<<dp[n-1].fs<<' '<<dp[n-1].sc<<endl;
    ans = min(ans,min(dp[n-1].fs,dp[n-1].sc));
    cout<<ans;
}
