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
vector<int> paths[mxn];
pair<int,vector<int>> ans;
int n;
int dfs(int now,int par){
	int sz = 1;
	int big = 0;
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		int tmp = dfs(nxt,now);
		big = max(big,tmp);
		sz += tmp;
	}
	big = max(big,n-sz);
	if(ans.fs>big){
		ans.fs = big;
		ans.sc = {now};
	}
	else if(ans.fs == big){
		ans.sc.push_back(now);
	}
	return sz;
}
int main(){
	io
	cin>>n;
	ans = make_pair(n,vector<int>(1,1));
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(0,0);
	sort(_all(ans.sc));
	for(auto i:ans.sc)cout<<i<<'\n';
	return 0;
}

