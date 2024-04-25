#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e5+10;

set<pll> childs[mxn];
vector<int> tree[mxn];
int par[mxn];
ll val[mxn],dp[mxn],sz[mxn];
ll n,q;

void dfs(int now){
	sz[now] = 1;
	dp[now] = val[now];
	for(auto nxt:tree[now]){
		if(nxt == par[now])continue;
		par[nxt] = now;
		dfs(nxt);
		childs[now].insert({sz[nxt],-nxt});
		dp[now] += dp[nxt];
		sz[now] += sz[nxt];
	}
	return;
}

void rotate(int now){
	if(childs[now].empty())return;
	int p = par[now];
	int bs = -childs[now].rbegin()->sc;
	childs[now].erase({sz[bs],-bs});
	childs[p].erase({sz[now],-now});
	sz[p] -= sz[now];
	sz[now] -= sz[bs];
	sz[bs] += sz[now];
	dp[p] -= dp[now];
	dp[now] -= dp[bs];
	dp[bs] += dp[now];
	par[now] = bs;
	par[bs] = p;
	childs[bs].insert({sz[now],-now});
	sz[p] += sz[bs];
	dp[p] += dp[bs];
	childs[p].insert({sz[bs],-bs});
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>val[i];
	for(int i = 1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll k;
			cin>>k;
			cout<<dp[k]<<'\n';
		}
		else{
			ll p;
			cin>>p;
			rotate(p);
		}
	}
}
