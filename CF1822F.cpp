#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
ll dep[mxn];
pll dp[mxn];
pll src[mxn];

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
		ll d = dp[nxt].fs+1;
		if(d>dp[now].fs)swap(dp[now].fs,dp[now].sc),dp[now].fs = d,swap(src[now].fs,src[now].sc),src[now].fs = nxt;
		else if(d>dp[now].sc)dp[now].sc = d,src[now].sc = nxt;
	}
	return;
}

void dfs2(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		ll d;
		if(nxt == src[now].fs){
			d = dp[now].sc+1;
		}
		else d = dp[now].fs+1;
		if(d>dp[nxt].fs)swap(dp[nxt].fs,dp[nxt].sc),swap(src[nxt].fs,src[nxt].sc),dp[nxt].fs = d,src[nxt].fs = now;
		else if(d>dp[nxt].sc)dp[nxt].sc = d,src[nxt].sc = now;
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	ll n,k,c;
	cin>>n>>k>>c;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	dfs2(1,1);
	ll ans = dp[1].fs*k;
	/*
	for(int i = 1;i<=n;i++)cout<<dp[i].fs<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++)cout<<dp[i].sc<<' ';cout<<'\n';

   */
	for(int i = 1;i<=n;i++){
		ans = max(ans,dp[i].fs*k-c*dep[i]);
	}
	cout<<ans<<'\n';

	for(int i = 0;i<=n;i++)tree[i].clear();
	for(int i = 0;i<=n;i++)dp[i] = src[i] = {0,0};
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
