#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> tree[mxn];
int dp[mxn];
int dep[mxn];
int ans = 0;

void dfs(int now){
	dp[now] = 1;
	dep[now] = 1;
	int tmp = 0;
	for(auto nxt:tree[now]){
		dfs(nxt);
		dep[now] = max(dep[now],dep[nxt]+1);
		tmp += dp[nxt];
	}
	dp[now] = max(dep[now],tmp);
	ans = max(ans,dp[now]);
	return;
}

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i+1);
	}
	dfs(1);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
