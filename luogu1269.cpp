#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e4+10;
vector<pii> tree[mxn];
int n;
int S;
pii dp[mxn];
int ans = 0;

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		if(nxt.sc>=S){
			cout<<"No solution.";
			exit(0);
		}
		dfs(nxt.fs,now);
		dp[now].fs += dp[nxt.fs].fs;
		dp[nxt.fs].sc += nxt.sc;
		if(dp[nxt.fs].sc>S){
			dp[now].fs++;
			dp[nxt.fs].sc = nxt.sc;
		}
		dp[now].sc = max(dp[now].sc,dp[nxt.fs].sc);
	}
	if(dp[now].sc>S)dp[now].sc = 0,dp[now].fs++;
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i =1 ;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,b;
			cin>>a>>b;
			tree[i].push_back({a,b});
		}
	}
	cin>>S;
	dfs(1,1);
	cout<<dp[1].fs;
}
