#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll,ll> dp;
ll n,x;
void dfs(ll now){
    if(to_string(now).size() == n){
        dp[now] = 0;
        return;
    }
    dp[now] = -1;
    string s = to_string(now);
    ll ans = INT_MAX;
    for(auto i:s){
        ll tmp = now*(i-'0');
        if(dp.count(tmp) == 0){
            dfs(tmp);
        }
        if(dp[tmp] == -1)continue;
        else ans = min(ans,dp[tmp]+1);
    }
    if(ans >=INT_MAX)dp[now] = -1;
    else dp[now] = ans;
}
int main(){
    cin>>n>>x;
    dp[x] = -1;
    dfs(x);
    cout<<dp[x];
}
