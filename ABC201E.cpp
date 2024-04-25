#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
#define pll pair<ll,ll>
const int bits = 62;
const int mxn = 2e5+10;
vector<pll> paths[mxn];
ll val[mxn];
ll cnt[bits][2];
const ll mod = 1e9+7;

void dfs(int now,int par){
    for(auto nxt:paths[now]){
        if(nxt.fs == par)continue;
        val[nxt.fs] = val[now]^nxt.sc;
        dfs(nxt.fs,now);
    }
    return;
}
int main(){
    ll n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    dfs(1,1);
    ll ans = 0;
    // for(int i = 1;i<=n;i++)cout<<val[i]<<' ';cout<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<bits;j++){
            ans += (1LL<<j)%mod*cnt[j][val[i]&1^1]%mod;
            cnt[j][val[i]&1]++;
            if(ans>=mod)ans -= mod;
            val[i]>>=1;
        }
        // for(int j = 0;j<4;j++)cout<<cnt[j][0]<<' ';cout<<endl;
        // for(int j = 0;j<4;j++)cout<<cnt[j][1]<<' ';cout<<endl;cout<<endl;
    }
    cout<<ans;
}