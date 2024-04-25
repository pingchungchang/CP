#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1e5+10;
vector<pii> tree[mxn];
int n;
int ans = 0;
int dfs(int now,int fa){
	pii dp = {0,0};
	for(auto &nxt:tree[now]){
		if(nxt.fs == fa)continue;
		int tmp = dfs(nxt.fs,now)+nxt.sc;
		if(tmp>=dp.fs){
			swap(dp.fs,dp.sc);
			dp.fs = tmp;
		}
		else if(tmp>dp.sc)dp.sc = tmp;
		ans = max(ans,dp.fs+dp.sc);
	}
	ans = max(ans,dp.fs);
	return dp.fs;
}
void solve(){
	ans = 0;
	for(auto &i:tree)i.clear();
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	dfs(1,1);
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}

