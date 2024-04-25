#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

ll pw(ll k){
    ll ans = 1;
    ll now = 2;
    while(k != 0){
        if((k&1) != 0)ans *= now;
        now*= now;
        k>>=1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vv(n);
    for(int i = 0;i<n;i++){
        cin>>vv[i].first;
    }
    for(int i = 0;i<n;i++)cin>>vv[i].second;
    sort(vv.begin(),vv.end());
    vector<int> v(n+1,0);
    for(int i = 1;i<=n;i++)v[i] = vv[i-1].second;
    ll ans = 1;
    vector<ll> dp(n+1,0);
    dp[1] = 1;
    dp[2] = 3;
    for(ll i = 3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i]%= mod;
    }
    for(int i = 1;i<=n;i++){
        if(v[i] != -1){
            ll cnt = 0;
            int now = i;
            while(v[now] != -1){
                int nxt = v[now];
                v[now] = -1;
                cnt++;
                now = nxt;
            }
            ans = ans*dp[cnt]%mod;
        }
    }
    cout<<ans;
}
