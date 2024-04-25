#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 1e4+10;
vector<int> tree[mxn];
int dp[mxn][3];
int n;

int dfs(int now,int par){
	dp[now][0] = dp[now][1] = dp[now][2] = 0;
	int small = 1e9;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now][0] += dp[nxt][2];
		dp[now][1] += min({dp[nxt][0],dp[nxt][1],dp[nxt][2]});
		small = min(small,dp[nxt][1]-min({dp[nxt][1],dp[nxt][2]}));
		dp[now][2] += min(dp[nxt][1],dp[nxt][2]);
	}
	dp[now][2] += small;
	dp[now][1]++;
	return min(dp[now][1],dp[now][2]);
}

void solve(){
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout<<dfs(1,1)<<'\n';
	for(int i =0;i<=n;i++)tree[i].clear();
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
