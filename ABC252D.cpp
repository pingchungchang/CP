#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    map<ll,ll> mp;
    for(ll i = 0;i<n;i++){
        ll k;cin>>k;
        mp[k]++;
    }
    ll dp[3] = {0LL,0LL,0LL};
    ll ans = 0;
    for(auto i:mp){
        dp[2] += i.second*dp[1];
        dp[1] += dp[0]*i.second;
        dp[0] += i.second;
    }
    cout<<dp[2];
}
