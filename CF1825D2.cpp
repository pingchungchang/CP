#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
const ll mod = 1e9+7;
ll fac[mxn],ifac[mxn];
vector<int> tree[mxn];
ll sz[mxn],dp[mxn],par[mxn];
ll n,k;
ll ans = 0;

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
ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}
ll mub(ll a,ll b){
	a = a+mod-b;
	if(a>=mod)a -= mod;
	return a;
}
ll C(ll a,ll b){
	if(a<b)return 0;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}

void dfs1(int now,int par){
	if(now != par)ans = mad(ans,C(sz[now],k/2)*C(n-sz[now],k/2)%mod);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs1(nxt,now);
	}
	return;
}

void solve(){
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	if(k&1){
		cout<<"1\n";
		return;
	}
	dfs(1,1);
	dfs1(1,1);
	cout<<(ans+C(n,k))%mod*inv(C(n,k))%mod;
	return;
}
int main(){
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
/*
k>=i>k/2
dp[i] = dp[i-1]*2

i>k
dp[i] = dp[i-1]+C(n-i,k/2-1)*C(i-1,k/2)
*/
