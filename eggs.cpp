#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

const int mxn = 909;
vector<int> tree[mxn];
vector<int> v;
int n;

void dfs(int now,int par){
	v.push_back(now);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
	}
	return;
}

inline bool check(int tar){
	vector<int> vv;
	for(int i = 0;i<=tar;i++)vv.push_back(v[i]);
	return query(vv);
}

int findEgg (int N, vector < pair < int, int > > bridges){
	for(int i = 0;i<=n;i++)tree[i].clear();
	v.clear();
	n = N;
	for(auto &i:bridges){
		tree[i.first].push_back(i.second);
		tree[i.second].push_back(i.first);
	}
	dfs(1,1);
	int l = 0,r = n-1;
	while(l != r){
		int mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	return v[l];
}
