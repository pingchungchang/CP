#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
int dp[mxn];
vector<int> tree[mxn];
int n,m;

void dfs(int now){
	for(auto nxt:tree[now]){
		dp[nxt] = max(dp[nxt],dp[now]-1);
		dfs(nxt);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		dp[x] = max(dp[x],y+1);
	}
	dfs(1);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(dp[i])ans++;
	}
	cout<<ans;
}
