#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int n;
int par[mxn][20],dep[mxn];
int rlen = 0;
vector<int> tree[mxn],v;

void dfs(int now){
	for(int i = 1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
	for(auto nxt:tree[now]){
		if(nxt == par[now][0])continue;
		par[nxt][0] = now;
		dep[nxt] = dep[now]+1;
		dfs(nxt);
	}
	return;
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	for(int i = 19;i>=0;i--){
		if(d&(1<<i))a = par[a][i];
	}
	for(int i = 19;i>=0;i--){
		if(par[a][i] != par[b][i]){
			a = par[a][i],b = par[b][i];
		}
	}
	if(a == b)return a;
	else return par[a][0];
}

int dist(int a,int b){
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}

pii calc(int h,int a,int b,int k){
	if(dep[lca(h,k)]<dep[h]){
		return make_pair(dist(h,k),h);
	}
	pii t1 = {dist(k,lca(a,k)),lca(a,k)};
	pii t2 = {dist(k,lca(b,k)),lca(b,k)};
	return min(t1,t2);
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
	par[1][0] = 1;
	dfs(1);
	int q;
	cin>>q;
	while(q--){
		int a,b,s,e,k;
		cin>>a>>b>>s>>e>>k;
		rlen = dist(a,b)+1;
		v.clear();
		int h = lca(a,b);
		bool flag = false;
		if(dist(s,e)%2 == k%2&&dist(s,e)<=k)flag = true;
		auto ta = calc(h,a,b,s);
		auto tb = calc(h,a,b,e);
		s = ta.sc,e = tb.sc;
		int d1 = ta.fs+tb.fs + dist(s,e);
		int d2 = ta.fs+tb.fs+rlen-dist(s,e);
		if(d1<=k&&d1%2 == k%2)flag = true;
		if(d2<=k&&d2%2 == k%2)flag = true;
		//cout<<dist(a,b)<<' '<<ta.fs<<' '<<ta.sc<<' '<<tb.fs<<' '<<tb.sc<<'\n';
		//cout<<dist(a,b)<<' '<<d1<<' '<<d2<<'\n';
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
