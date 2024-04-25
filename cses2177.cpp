#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<pii> paths[mxn];
pii ans[mxn*2];
int low[mxn],idx[mxn],cnt;
bitset<mxn> vis;

void dfs(int now,int par){
	vis[now] = true;
	low[now] = idx[now] = ++cnt;
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		if(!idx[nxt.fs]){
			ans[nxt.sc] = {now,nxt.fs};
			dfs(nxt.fs,now);
		}
		else{
			if(idx[nxt.fs]>idx[now])ans[nxt.sc] = {nxt.fs,now};
			else ans[nxt.sc] = {now,nxt.fs};
		}
		low[now] = min(low[now],low[nxt.fs]);
	}
	if(now != par&&low[now] == idx[now]){
		cout<<"IMPOSSIBLE\n";
		exit(0);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	dfs(1,1);
	if(vis.count() != n){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i].fs<<' '<<ans[i].sc<<'\n';
	}
	return 0;
}
