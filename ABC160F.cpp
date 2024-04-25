#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
ll fac[mxn];
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
ll dp[mxn],sz[mxn],n;
vector<int> tree[mxn];

void dfs1(int now,int par){
    dp[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs1(nxt,now);
        sz[now] += sz[nxt];
        dp[now] = dp[now]*C(sz[now],sz[nxt])%mod*dp[nxt]%mod;
    }
    sz[now]++;
    return;
}
void dfs2(int now,int par){
    if(now == par);
    else{
        auto tmp = dp[par];
        tmp = tmp*inv(C(n-1,sz[now]))%mod*inv(dp[now])%mod;
        dp[now] = dp[now]*C(n-1,n-sz[now])%mod*tmp%mod;
    }
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs2(nxt,now);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++){
        fac[i] = fac[i-1]*i%mod;
    }
    cin>>n;
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(1,1);
    // for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<sz[i]<<' ';cout<<endl;
    dfs2(1,1);
    for(int i = 1;i<=n;i++)cout<<dp[i]<<'\n';
    return 0;
}