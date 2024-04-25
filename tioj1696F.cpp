#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
#define pll pair<ll,ll>
#define pii pair<int,int>

const int mxn = 1e5+10;
int sz[mxn];
bitset<mxn> del;
int bit[mxn];
int ans[mxn];
int dep[mxn];
int val[mxn];
int deep = 0;
int add[mxn];
vector<int> paths[mxn];
int pt = 0;
void modify(int p,int v){
	p++;
	for(;p<=deep+1;p += p&-p)bit[p] += v;
	return;
}
int getval(int p){
	p++;
	int re = 0;
	if(p>deep+1)p = deep+1;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
void find_sz(int now,int par){
	sz[now] = 1;
	for(auto nxt:paths[now]){
		if(del[nxt]||nxt == par)continue;
		find_sz(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}
int centroid(int now,int tar,int par){
	for(auto nxt:paths[now]){
		if(del[nxt]||nxt == par)continue;
		if(sz[nxt]>=tar)return centroid(nxt,tar,now);
	}
	return now;
}
void find_dep(int now,int par,int d){
	dep[now] = d;
	deep = max(deep,dep[now]);
	for(auto nxt:paths[now]){
		if(nxt == par||del[nxt])continue;
		find_dep(nxt,now,d+1);
	}
}
void dfs(int now,int par){
	modify(dep[now],1);
	for(auto nxt:paths[now]){
		if(nxt == par||del[nxt])continue;
		dfs(nxt,now);
	}
	return;
}
void dfs1(int now,int par){
	add[pt++] = dep[now];
	for(auto nxt:paths[now]){
		if(nxt == par||del[nxt])continue;
		dfs1(nxt,now);
	}
	return;
}
void dfs2(int now,int par){
	if(val[now]>=dep[now]){
		ans[now] += getval(val[now]-dep[now]);
	}
	for(auto nxt:paths[now]){
		if(del[nxt]||nxt == par)continue;
		dfs2(nxt,now);
	}
	return;
}
void cendfs(int now){
	find_sz(now,now);
	int cen = centroid(now,sz[now]/2,now);
	deep = 0;
	dep[cen] = 0;
	for(auto nxt:paths[cen]){
		if(!del[nxt])find_dep(nxt,cen,1);
	}
//	cout<<cen<<' '<<deep<<',';
	fill(bit,bit+deep+9,0);
	modify(0,1);
	for(auto nxt:paths[cen]){
		if(!del[nxt])dfs(nxt,cen);
	}
	ans[cen] += getval(val[cen]);
	for(auto nxt:paths[cen]){
		if(del[nxt])continue;
		pt = 0;
		dfs1(nxt,cen);
		for(int i = 0;i<pt;i++)modify(add[i],-1);
		dfs2(nxt,cen);
		for(int i = 0;i<pt;i++)modify(add[i],1);
	}
//	ans[cen] += getval(val[cen]);


	del[cen] = true;
	for(auto nxt:paths[cen]){
		if(!del[nxt])cendfs(nxt);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>val[i];
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	cendfs(1);
	for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
}
