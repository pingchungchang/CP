#include <bits/stdc++.h>
using namespace std;


#define ll long long

ll n,m,k,p;

ll pw(ll val, ll t){
    ll ans = 1;
    ll now = val%p;
    while(t != 0){
        if((t&1) != 0){
            ans = (ans*now)%p;
        }
        now = (now*now)%p;
        t>>=1;
    }
    return ans;
}
void solve(){
    vector<ll>dp(k,0LL);
    n%= p;
    dp[0] = n+1;
    for(ll i = 1;i<k;i++){
        dp[i] += n*dp[i-1]%p;
        if(i<m+1)dp[i] += pw(n,i);
        else{
            dp[i] += dp[i-m-1]*pw(n,m)%p;
        }
        dp[i]%= p;
    }
    cout<<dp[k-1]%p<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m>>k>>p){
        if(n == 0&&m == 0&&k == 0&&p == 0)return 0;
        solve();
    }
}
