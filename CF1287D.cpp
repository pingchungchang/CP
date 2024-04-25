#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2020;
vector<int> tree[mxn],vals[mxn];
int cnt[mxn],dp[mxn],sz[mxn];
int n,rt;

void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		dfs1(nxt);
		sz[now] += sz[nxt];
	}
	return;
}

void dfs2(int now){
	dp[now] = vals[now][cnt[now]];
	if(cnt[now]>=sz[now]){
		cout<<"NO\n";
		exit(0);
	}
	int pt = 0;
	for(auto nxt:tree[now]){
		while(vals[nxt].size() != sz[nxt]){
			if(pt == cnt[now])pt++;
			vals[nxt].push_back(vals[now][pt]);
			pt++;
		}
		dfs2(nxt);
	}
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int p,c;
		cin>>p>>c;
		cnt[i] = c;
		if(p == 0)rt = i;
		else tree[p].push_back(i);
	}
	dfs1(rt);
	for(int i = 1;i<=n;i++)vals[rt].push_back(i);
	dfs2(rt);
	cout<<"YES\n";
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';
}
