#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O3")
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
ll ans = 0;
vector<int> tree[mxn];
bitset<mxn> del;
int dep[mxn],sz[mxn];
int cnt[mxn];
int n,k;

void get_sz(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		get_sz(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}

int get_centroid(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		if(sz[nxt]>tar)return get_centroid(nxt,now,tar);
	}
	return now;
}

vector<int> st;
void dfs1(int now,int par){
	if(k>=dep[now])ans += cnt[k-dep[now]];
	st.push_back(dep[now]);
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		dep[nxt] = dep[now]+1;
		dfs1(nxt,now);
	}
	return;
}

void dfs2(int now,int par){
	cnt[dep[now]]++;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		dfs2(nxt,now);
	}
	return;
}

void cendfs(int now,int par){
	get_sz(now,now);
	int cen = get_centroid(now,now,(sz[now])/2);
	del[cen] = true;
	cnt[0] = 1;
	//cout<<now<<' '<<cen<<endl;
	for(auto nxt:tree[cen]){
		if(del[nxt])continue;
		dep[nxt] = 1;
		dfs1(nxt,nxt);
		while(!st.empty())cnt[st.back()]++,st.pop_back();
		//dfs2(nxt,nxt);
	}
	fill(cnt,cnt+sz[now],0);
	for(auto nxt:tree[cen]){
		if(del[nxt])continue;
		cendfs(nxt,cen);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ans = 0;
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cendfs(1,1);
	cout<<ans;
}
