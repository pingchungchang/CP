#include "deliveries.h"
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
#define ll long long
#define pll pair<ll,ll>

const int mxn = 1e5+10;
vector<pii> tree[mxn];
ll W[mxn],sz[mxn],dep[mxn];

void init(int N, std::vector<int> U, std::vector<int> V, std::vector<int> t, std::vector<int> w) {
	for(int i = 0;i<N-1;i++){
		int a = U[i],b = V[i],c = t[i];
		tree[a].push_back(pll(b,c));
		tree[b].push_back(pll(a,c));
	}
	for(int i = 0;i<N;i++)W[i] = w[i];
	W[0] += 1;
	return;
}

void szdfs(int now,int par){
	sz[now] = W[now];
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		szdfs(nxt.fs,now);
		sz[now] += sz[nxt.fs];
	}
	return;
}

int find_centroid(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		if(sz[nxt.fs]>tar)return find_centroid(nxt.fs,now,tar);
	}
	return now;
}

ll dfs1(int now,int par){
	ll re = 0;
	re += W[now]*dep[now];
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dep[nxt.fs] = dep[now]+nxt.sc;
		re += dfs1(nxt.fs,now);
	}
	return re;
}

long long max_time(int S, int X) {
	if(!S)X += 1;
	W[S] = X;
	szdfs(0,0);
	int cen = find_centroid(0,0,(sz[0])/2);
	dep[cen] = 0;
	return dfs1(cen,cen)*2;
}
