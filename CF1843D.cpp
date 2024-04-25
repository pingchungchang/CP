#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int dp[mxn];
int n;

void dfs(int now,int par){
	dp[now] = 0;
	if(now != par&&tree[now].size() == 1)dp[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now] += dp[nxt];
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)tree[i].clear();
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	int q;
	cin>>q;
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<1LL*dp[a]*dp[b]<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
