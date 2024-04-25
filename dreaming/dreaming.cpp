#include "dreaming.h"
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;

vector<pii> tree[mxn];
bitset<mxn> vis;
vector<int> all;
vector<pii> v;
pii dp[mxn];
int dp2[mxn];

void dfs1(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dfs1(nxt.fs,now);
		if(dp[now].fs<dp[nxt.fs].fs+nxt.sc){
			swap(dp[now].fs,dp[now].sc);
			dp[now].fs = dp[nxt.fs].fs+nxt.sc;
		}
		else if(dp[now].sc<dp[nxt.fs].fs+nxt.sc)dp[now].sc = dp[nxt.fs].fs+nxt.sc;
	}
	return;
}

void dfs2(int now,int par){
	vis[now] = true;
	all.push_back(now);
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		int val = 0;
		if(dp[nxt.fs].fs+nxt.sc == dp[now].fs)val = dp[now].sc;
		else val = dp[now].fs;
		val += nxt.sc;
		if(val>dp[nxt.fs].fs){
			swap(dp[nxt.fs].fs,dp[nxt.fs].sc);
			dp[nxt.fs].fs = val;
		}
		else if(val>dp[nxt.fs].sc)dp[nxt.fs].sc = val;
		dfs2(nxt.fs,now);
	}
	return;
}

int dfs3(int now,int par){
	dp[now] = pii(0,0);
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dfs3(nxt.fs,now);
		dp2[now] = max(dp2[now],dp2[nxt.fs]);
		if(dp[now].fs<dp[nxt.fs].fs+nxt.sc){
			swap(dp[now].fs,dp[now].sc);
			dp[now].fs = dp[nxt.fs].fs+nxt.sc;
		}
		else if(dp[now].sc<dp[nxt.fs].fs+nxt.sc)dp[now].sc = dp[nxt.fs].fs+nxt.sc;
	}
	dp2[now] = max(dp2[now],dp[now].fs+dp[now].sc);
	return dp2[now];
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for(int i = 0;i<M;i++){
		int a = A[i],b = B[i],c = T[i];
		tree[a].push_back(pii(b,c));
		tree[b].push_back(pii(a,c));
	}
	for(int i = 0;i<N;i++){
		if(vis[i])continue;
		dfs1(i,i);
		dfs2(i,i);
		pii mn = pii(dp[i].fs,i);
		for(auto &j:all)mn = min(mn,pii(dp[j].fs,j));
		v.push_back(mn);
		all.clear();
	}
	sort(v.rbegin(),v.rend());
	for(int i = 1;i<v.size();i++){
		int ta = v[i].sc,tb = v[0].sc;
		tree[ta].push_back(pii(tb,L));
		tree[tb].push_back(pii(ta,L));
	}
	return dfs3(0,0);
}
