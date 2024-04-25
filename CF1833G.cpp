#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
bool flag = true;
vector<pii> tree[mxn];
vector<int> ans;
int dp[mxn];

void dfs(int now,int par){
	dp[now] = 1;
	int p = 0;
	for(auto nxt:tree[now]){
		if(nxt.sc == par)continue;
		dfs(nxt.fs,nxt.sc);
		if(dp[nxt.fs]&&dp[now]){
			p += dp[nxt.fs];
			if(p == 2)ans.push_back(par);
		}
	}
	if(p>2)flag = false;
	if(p == 1)dp[now] = 2;
	if(p == 0)dp[now] = 1;
	if(p == 2)dp[now] = 0;
	//cout<<now<<":"<<dp[now]<<endl;
	return;
}

void solve(){
	int n;
	cin>>n;
	fill(dp,dp+n+1,0);
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back({b,i});
		tree[b].push_back({a,i});
	}
	flag = true;
	dfs(1,-1);
	if(dp[1])flag = false;
	if(!flag)cout<<-1<<'\n';
	else{
		sort(ans.rbegin(),ans.rend());
		if(ans.size()>=1&&ans.back() == -1)ans.pop_back();
		cout<<ans.size()<<'\n';
		for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	}
	ans.clear();
	for(int i = 1;i<=n;i++)tree[i].clear();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
