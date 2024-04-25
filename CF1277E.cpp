#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int dp[mxn],sz[mxn];
int n,m,a,b;

int dfs(int now,int par,int tar){
	if(now == tar)dp[now] = true;
	sz[now] = 1;
	int total = 0;
	for(auto nxt:paths[now]){
		if(sz[nxt])continue;
		dfs(nxt,now,tar);
		sz[now] += sz[nxt];
		if(dp[nxt])total = -sz[nxt],dp[now] = true;
	}
	return total+sz[now]-1;
}

void solve(){
	for(int i = 1;i<=n;i++){
		paths[i].clear();
		dp[i] = sz[i] = 0;
	}
	cin>>n>>m>>a>>b;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	fill(dp,dp+n+1,0);fill(sz,sz+n+1,0);
	ll ta = dfs(a,0,b);
	fill(dp,dp+n+1,0);fill(sz,sz+n+1,0);
	ll tb = dfs(b,0,a);
	//cout<<ta<<' '<<tb<<',';
	cout<<ta*tb<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
