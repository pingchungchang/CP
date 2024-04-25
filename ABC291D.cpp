#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pll pair<ll,ll>
const ll mod = 998244353;
const ll mxn = 2e5+10;
ll dp[2];
pii arr[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    dp[0] = dp[1] = 1;
    for(int i = 1;i<=n;i++){
        cin>>arr[i].fs>>arr[i].sc;
    }
    dp[0] = dp[1] = 1;
    for(int i = 2;i<=n;i++){
        ll dp2[2] = {0,0};
        if(arr[i].fs != arr[i-1].fs)dp2[0] += dp[0];
        if(arr[i].fs != arr[i-1].sc)dp2[0] += dp[1];
        if(arr[i].sc != arr[i-1].fs)dp2[1] += dp[0];
        if(arr[i].sc != arr[i-1].sc)dp2[1] += dp[1];
        dp[0] = dp2[0];
        dp[1] = dp2[1];
        if(dp[0]>=mod)dp[0] -= mod;
        if(dp[1]>=mod)dp[1] -= mod;
    }
    cout<<(dp[0]+dp[1])%mod;
}