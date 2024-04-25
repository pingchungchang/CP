#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<pair<int,pii>> edges;
vector<pii> tree[mxn];
int par[mxn][20],dp[mxn][20],dep[mxn];
int dsu[mxn],sz[mxn];
int N,Q;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
}

void dfs(int now){
	for(int i = 1;i<20;i++)
		par[now][i] = par[par[now][i-1]][i-1],dp[now][i] = min(dp[now][i-1],dp[par[now][i-1]][i-1]);
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now][0])continue;
		par[nxt.fs][0] = now;
		dp[nxt.fs][0] = nxt.sc;
		dep[nxt.fs] = dep[now]+1;
		dfs(nxt.fs);
	}
	return;
}
pii lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	int re = N;
	for(int i = 19;i>=0;i--){
		if(d&(1<<i))re = min(re,dp[a][i]),a = par[a][i];
	}
	for(int i = 19;i>=0;i--){
		if(par[a][i] != par[b][i])re = min({re,dp[a][i],dp[b][i]}),a = par[a][i],b = par[b][i];
	}
	if(a != b)re = min({re,dp[a][0],dp[b][0]}),a = b = par[a][0];
	return {a,re};
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j*j<=i;j++){
			if(i%j == 0){
				if(i+j<=N)edges.push_back({j,{i,i+j}});
				if(i-j>=1)edges.push_back({j,{i,i-j}});
				if(i+i/j<=N)edges.push_back({i/j,{i,i+i/j}});
				if(i-i/j>=1)edges.push_back({i/j,{i,i-i/j}});
			}
		}
		dsu[i] = i,sz[i] = 1;
	}
	sort(edges.rbegin(),edges.rend());
	for(auto &i:edges){
		if(root(i.sc.fs) == root(i.sc.sc))continue;
		tree[i.sc.fs].push_back({i.sc.sc,i.fs});
		tree[i.sc.sc].push_back({i.sc.fs,i.fs});
		onion(i.sc.fs,i.sc.sc);
	}
	par[1][0] = 1;
	dfs(1);
	while(Q--){
		int a,b;
		cin>>a>>b;
		auto re = lca(a,b);
		cout<<re.sc<<'\n';
	}
	return 0;
}
