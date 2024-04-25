#include <bits/stdc++.h>
#include "lib1164.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1e6+10;
MAP g1,g2;
vector<pii> tree1[mxn],tree2[mxn];
bitset<mxn> isbig,issmall;
pii dfs(vector<pii> tree[],int dep,int now,int par){
	pii ans = {dep,now};
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		ans = max(ans,dfs(tree,dep+nxt.sc,nxt.fs,now));
	}
	return ans;
}
int main(){
	int n = init();
	int big = 0,small = 0;
	vector<int> v[2];
	for(int i = 1;i<n;i+=2){
		int re = query(i-1,i);
		if(re){
			v[0].push_back(i-1);
			v[1].push_back(i);
		}
		else{
			v[0].push_back(i);
			v[1].push_back(i-1);
		}
	}
	if(n&1){
		v[0].push_back(n-1);
		v[1].push_back(n-1);
	}
	big = v[0][0],small = v[1][0];
	for(int i = 1;i<v[0].size();i++){
		if(query(v[0][i],big))big = v[0][i];
	}
	for(int i = 1;i<v[1].size();i++){
		if(query(small,v[1][i]))small = v[1][i];
	}
	g1 = getct(big);
	g2 = getct(small);
	for(int i = 0;i<g1.k;i++){
		tree1[g1.x[i]].push_back({g1.y[i],g1.len[i]});
		tree1[g1.y[i]].push_back({g1.x[i],g1.len[i]});
	}
	for(int i = 0;i<g2.k;i++){
		tree2[g2.x[i]].push_back({g2.y[i],g2.len[i]});
		tree2[g2.y[i]].push_back({g2.x[i],g2.len[i]});
	}	
	pii ans = {0,0};
	auto tmp = dfs(tree1,0,0,0);
	ans.fs = dfs(tree1,0,tmp.sc,tmp.sc).fs;
	tmp = dfs(tree2,0,0,0);
	ans.sc = dfs(tree2,0,tmp.sc,tmp.sc).fs;
	answer(ans.fs,ans.sc);
	return 0;
}

