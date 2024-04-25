#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
struct Edge{
	int id,from,to;
	Edge(){}
	Edge(int ii,int ff,int tt){
		id = ii,from = ff,to = tt;
	}
};
vector<Edge> tree[mxn];
int pre[mxn];
int dp[mxn];
void dfs(int now,int pid){
	dp[pid] = 1;
	for(auto nxt:tree[now]){
		if(nxt.id == pid)continue;
		pre[nxt.id] = pid;
		dfs(nxt.to,nxt.id);
		dp[pid] = max(dp[pid],dp[nxt.id]+(nxt.id<pid));
	}
	return;
}

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(Edge(i,a,b));
		tree[b].push_back(Edge(i,b,a));
	}
	dfs(1,0);
	cout<<dp[0]<<'\n';
	for(int i = 1;i<=n;i++){
		tree[i].clear();
		pre[i] = dp[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
