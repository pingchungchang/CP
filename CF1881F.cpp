#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e5+10;
const int inf = 1e9+10;
vector<int> tree[mxn];
int arr[mxn];
pii down[mxn];
int up[mxn],ans[mxn];
int n,m;

void dfs(int now,int par){
	up[now] = down[now].fs = down[now].sc = ans[now] = -inf;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(down[nxt].fs+1>down[now].fs){
			swap(down[now].sc,down[now].fs);
			down[now].fs = down[nxt].fs+1;
		}
		else if(down[now].sc<down[nxt].fs+1){
			down[now].sc = down[nxt].fs+1;
		}
	}
	if(arr[now]){
		up[now] = 0;
		if(0>down[now].fs){
			swap(down[now].fs,down[now].sc);
			down[now].fs = 0;
		}
		else if(0>down[now].sc)down[now].sc = 0;
	}
	ans[now] = down[now].fs;
	return;
}

void dfs2(int now,int par){
	ans[now] = max(ans[now],up[now]);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		up[nxt] = up[now]+1;
		if(down[nxt].fs+1 == down[now].fs)up[nxt] = max(up[nxt],down[now].sc+1);
		else up[nxt] = max(up[nxt],down[now].fs+1);
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		arr[i] = 0;
		tree[i].clear();
	}
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		arr[k] = true;
	}
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	dfs2(1,1);
	//for(int i = 1;i<=n;i++)cout<<up[i]<<' ';cout<<'\n';
	cout<<*min_element(ans+1,ans+n+1)<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
