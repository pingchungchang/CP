#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;

int dep[mxn],fa[mxn],dp[mxn];
vector<int> v,tree[mxn];
int n;
pii r2;

void dfs(int now,int par){
	fa[now] = par;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
	}
}

void dfs1(int now,int par){
	if(dp[now])v.push_back(now);
	r2 = max(r2,make_pair(dep[now]-dep[v.back()],now));
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs1(nxt,now);
	}
	if(dp[now])v.pop_back();
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
	vector<int> pt;
	dep[1] = 0;
	dfs(1,0);
	pii big = {0,0};
	for(int i = 1;i<=n;i++){
		big = max(big,make_pair(dep[i],i));
	}
	pt.push_back(big.sc);
	dep[big.sc] = 0;
	dfs(big.sc,0);
	int ans = 0;
	big = {0,0};
	for(int i = 1;i<=n;i++){
		ans = max(ans,dep[i]);
		big = max(big,make_pair(dep[i],i));
	}
	pt.push_back(big.sc);
	while(fa[big.sc]){
		dp[big.sc] = 1;
		big.sc = fa[big.sc];
	}
	dp[big.sc] = 1;
	r2 = make_pair(0,0);
	dep[big.sc] = 0;
	dfs1(big.sc,0);
	pt.push_back(r2.sc);
	sort(pt.begin(),pt.end());
	pt.erase(unique(pt.begin(),pt.end()),pt.end());
	if(pt.size() == 2){
		for(int i = 1;i<=n;i++){
			if(pt[0] != i&&pt[1] != i){
				pt.push_back(i);
				break;
			}
		}
	}
	cout<<ans+r2.fs<<'\n';
	for(auto &i:pt)cout<<i<<' ';
	return 0;
}
