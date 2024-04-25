#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
const int mxn = 2020;
ll fac[mxn],ifac[mxn];
ll dp[mxn],sz[mxn];
vector<int> tree[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

inline ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

void dfs(int now,int par){
	sz[now] = 0;
	dp[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		sz[now] += sz[nxt];
		dp[now] = dp[now]*C(sz[now],sz[nxt])%mod*dp[nxt]%mod;
	}
	sz[now]++;
	return;
}

void solve(){
	ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
	ll ans = 0;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		dfs(i,i);
		ans += dp[i];
		if(ans>=mod)ans -= mod;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
