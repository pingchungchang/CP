#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<pll> tree[mxn];
ll dp[mxn];
ll arr[mxn];
ll ans = 0;
int n,k;

void dfs(int now,int par){
	dp[now] = arr[now];
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dfs(nxt.fs,now);
		ans += abs(dp[nxt.fs])*nxt.sc;
		dp[now] += dp[nxt.fs];
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i] -= k;
	for(int i = 1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	dfs(1,1);
	cout<<ans;
}
