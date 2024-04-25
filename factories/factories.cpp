#include "factories.h"
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,sse4,avx2")
const int mxn = 5e5+10;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

namespace TREE{
	vector<pii> tree[mxn];
	int dfn[mxn],dep[mxn],par[mxn][20],pt = 0;
	ll dp[mxn];
	void dfs(int now){
		dfn[now] = pt++;
		for(int i = 1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
		for(auto nxt:tree[now]){
			if(nxt.fs == par[now][0])continue;
			dep[nxt.fs] = dep[now]+1;
			dp[nxt.fs] = dp[now]+nxt.sc;
			par[nxt.fs][0] = now;
			dfs(nxt.fs);
		}
	}
	int LCA(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		int d = dep[a]-dep[b];
		for(int i = 19;i>=0;i--){
			if(d&(1<<i))a = par[a][i];
		}
		for(int i = 19;i>=0;i--){
			if(par[a][i] != par[b][i])a = par[a][i],b = par[b][i];
		}
		return a == b?a:par[a][0];
	}
	ll dist(int a,int b){
		return dp[a]+dp[b]-dp[LCA(a,b)]*2;
	}
}

void Init(int N, int A[], int B[], int D[]) {
	for(int i = 0;i<N-1;i++){
		int a = A[i],b = B[i],w = D[i];
		TREE::tree[a].push_back(pii(b,w));
		TREE::tree[b].push_back(pii(a,w));
	}
	TREE::par[0][0] = 0;
	TREE::dfs(0);
}

namespace PEKO{
	vector<pll> tree[mxn];
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	vector<int> tv;
	ll dist[mxn];
	void init(){
		for(auto &i:tv){
			dist[i] = 1e18;
			tree[i].clear();
		}
		tv.clear();
	}
	void GO(vector<int> &v){
		init();
		sort(v.begin(),v.end(),[](int a,int b){return TREE::dfn[a]<TREE::dfn[b];});
		int s = v.size();
		for(int i = 1;i<s;i++)v.push_back(TREE::LCA(v[i-1],v[i]));
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		sort(v.begin(),v.end(),[](int a,int b){return TREE::dfn[a]<TREE::dfn[b];});
		tv = v;
		for(int i = 1;i<v.size();i++){
			int a = TREE::LCA(v[i-1],v[i]);
			int b = v[i];
			ll d = TREE::dist(a,b);
			tree[a].push_back(pll(b,d));
			tree[b].push_back(pll(a,d));
		}
		return;
	}
	void DIJKSTRA(vector<int> &st){
		for(auto &i:tv)dist[i] = 1e18;
		for(auto &i:st){
			dist[i] = 0;
			pq.push(pll(dist[i],i));
		}
		while(!pq.empty()){
			auto [d,now] = pq.top();
			pq.pop();
			if(dist[now] != d)continue;
			for(auto [nxt,w]:tree[now]){
				if(dist[nxt]>d+w){
					dist[nxt] = d+w;
					pq.push(pll(dist[nxt],nxt));
				}
			}
		}
		return;
	}
}

long long Query(int S, int X[], int T, int Y[]) {
	vector<int> v;
	for(int i = 0;i<S;i++)v.push_back(X[i]);
	for(int i = 0;i<T;i++)v.push_back(Y[i]);
	v.push_back(0);
	PEKO::GO(v);
	v.clear();
	for(int i = 0;i<S;i++)v.push_back(X[i]);
	PEKO::DIJKSTRA(v);
	ll ans = 1e18;
	for(int i = 0;i<T;i++)ans = min(ans,PEKO::dist[Y[i]]);
	return ans;
}
