#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mini LONG_LONG_MIN
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    vector<vector<ll>> dp(2,vector<ll>(m,LONG_LONG_MIN));
    int now = 0,pre = 1;
    ll ans = 0;
    dp[now][0] = 0;

    if(m == 1){
        for(ll i = 0;i<n;i++){
            v[i] -= k;
            if(i != 0)v[i]= max(0LL,v[i-1]+v[i]);
            ans = max(ans,v[i]);
        }
        cout<<ans;
        return 0;
    }
    for(ll i = 0;i<n;i++){
        swap(now,pre);
        if(dp[pre][m-1] != LONG_LONG_MIN)dp[now][0] = max(0LL,dp[pre][m-1]+v[i]);
        else dp[now][0] = 0LL;
        dp[now][1] = (ll)dp[pre][0]-k+v[i];
        for(ll j = 2;j<m;j++){
            if(dp[pre][j-1] != LONG_LONG_MIN)dp[now][j] = dp[pre][j-1]+v[i];
        }
        for(ll j = 0;j<m;j++)ans = max(ans,dp[now][j]);
        //for(ll j = 0;j<m;j++)cout<<dp[now][j]<<' ';
        //cout<<'\n';
    }
    cout<<ans;
}
