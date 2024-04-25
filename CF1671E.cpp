#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mod2 = 1e9+7;
ll p2 = 29;
ll p = 19;
ll n;
string s;

ll pw(ll t,ll p,ll m){
    ll x = 1;
    ll now = p;
    while(t != 0){
        if((t&1))x *= now;
        now*= now;
        now %= m;
        x %= m;
        t>>=1;
    }
    return x;
}
ll mxn;
vector<ll> hval(1LL<<20,0LL);
vector<ll> hval2(1LL<<20,0LL);
vector<ll> dp(1LL<<20,1LL);
void dfs(ll now,ll depth){
    //cout<<now<<endl;
    if(now>mxn)return;
    ll l = now*2+1,r = now*2+2;
    dfs(l,depth-1);
    dfs(r,depth-1);
    if(hval[l] == hval[r]&&hval2[l] == hval2[r]){
        dp[now] = dp[l]*dp[r]%mod;
    }
    else{
        dp[now] = dp[l]*dp[r]*2%mod;
    }
    hval[now] = (min(hval[l],hval[r])*p%mod+s[now]-'A')*pw(1<<depth,p,mod)%mod+max(hval[l],hval[r]);
    hval[now]%= mod;
    hval2[now] = (min(hval2[l],hval2[r])*p%mod2+s[now]-'A')*pw(1<<depth,p2,mod2)%mod2+max(hval2[l],hval2[r]);
    hval2[now]%= mod;
    return;
}
int main(){
    cin>>n>>s;
    mxn = s.size()-1;
    dfs(0LL,n-1);
    cout<<dp[0]<<'\n';
    return 0;
}
