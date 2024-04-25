#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
vector<int> tree[mxn];
int n;
int dp[mxn][2];

void dfs(int now,int par){
	dp[now][1] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now][0] += dp[nxt][1];
		dp[now][1] += min(dp[nxt][0],dp[nxt][1]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	cout<<min(dp[1][0],dp[1][1]);
}
