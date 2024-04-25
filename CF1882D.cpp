#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int n;
ll ans,dp[mxn],sz[mxn],arr[mxn];

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now] += dp[nxt];
		sz[now] += sz[nxt];
		dp[now] += sz[nxt]*(arr[now]^arr[nxt]);
	}
	return;
}

void dfs2(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dp[nxt] = dp[nxt]+(sz[now]-sz[nxt])*(arr[nxt]^arr[now])+(dp[now]-sz[nxt]*(arr[nxt]^arr[now])-dp[nxt]);
		sz[nxt] = sz[now];
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	ans = 0;
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		dp[i] = sz[i] = 0;
	}
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	dfs2(1,1);
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
