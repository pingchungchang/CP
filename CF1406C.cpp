#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


const int mxn = 1e5+10;
vector<int> tree[mxn];
int sz[mxn];
bool cen[mxn];
int fa[mxn];
int n;
void dfs(int now,int par){
	sz[now] = 1;
	bool flag = true;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(sz[nxt]>n/2)flag = false;
		sz[now] += sz[nxt];
	}
	if((n-sz[now])>n/2)flag = false;
	if(flag)cen[now] = true;
	return;
}

void dfs2(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		fa[nxt] = now;
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)cen[i] = 0,fa[i] = 0,tree[i].clear();
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	vector<int> cc;
	for(int i = 1;i<=n;i++){
		if(cen[i])cc.push_back(i);
	}
	if(cc.size() == 1){
		cout<<1<<' '<<tree[1][0]<<'\n'<<1<<' '<<tree[1][0]<<'\n';
		return;
	}
	dfs2(cc[0],cc[1]);
	int leaf = 0;
	for(int i = 1;i<=n;i++){
		if(fa[i] && tree[i].size() == 1)leaf = i;
	}
	cout<<fa[leaf]<<' '<<leaf<<'\n'<<leaf<<' '<<cc[1]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
