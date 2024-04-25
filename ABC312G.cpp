#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int n;
ll dp[mxn],sz[mxn];
ll ans = 0;

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}
void dfs1(int now,int par){
	vector<ll> s;
	for(auto nxt:tree[now]){
		if(nxt == par)s.push_back(n-sz[now]);
		else s.push_back(sz[nxt]);
	}
	ll pre = 0;
	ll tans = 0;
	for(auto &i:s)tans += pre*i,pre += i;
	ans += tans;
	//cout<<now<<":"<<tans<<endl;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs1(nxt,now);
	}
	return;
}


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	dfs1(1,1);
	cout<<n*(n-1)*(n-2)/6-ans;
}
