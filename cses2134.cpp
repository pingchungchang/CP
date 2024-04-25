#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mxn = 2e5+10;
int big_son[mxn],link_top[mxn],segtree[mxn*4],idx[mxn],par[mxn],vals[mxn],sz[mxn],dep[mxn];
vector<int> childs[mxn];
int cnt = 0;
int n,q;
void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:childs[now]){
		if(nxt == par[now])continue;
		par[nxt] = now;
		dep[nxt] = dep[now]+1;
		dfs1(nxt);
		sz[now] += sz[nxt];
		if(big_son[now] < sz[nxt])big_son[now] = nxt;
	}
	return;
}
void dfs2(int now,int top){
	link_top[now] = top;
	idx[now] = cnt++;
	if(big_son[now] != 0){
		dfs2(big_son[now],top);
	}
	for(auto nxt:childs[now]){
		if(nxt == par[now]||nxt == big_son[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}
void changeval(int p,int v,int now,int l,int r){
	if(l == r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)changeval(p,v,now*2+1,l,mid);
	else changeval(p,v,now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}
int getval(int s,int e,int now,int l,int r){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(s,e,now*2+1,l,mid);
	else if(mid<s)return getval(s,e,now*2+2,mid+1,r);
	else return max(getval(s,e,now*2+1,l,mid),getval(s,e,now*2+2,mid+1,r));
}

int getans(int a,int b){
	int ta = link_top[a];
	int tb = link_top[b];
	if(dep[ta]<dep[tb]){
		swap(a,b);
		swap(ta,tb);
	}
	int ans = 0;
	while(ta != tb){
		ans = max(ans,getval(idx[ta],idx[a],0,0,cnt));
		a = par[ta];
		ta = link_top[a];
		if(dep[ta]<dep[tb]){
			swap(a,b);
			swap(ta,tb);
		}
	}
	if(dep[a]>dep[b])swap(a,b);
	ans = max(ans,getval(idx[a],idx[b],0,0,cnt));
	return ans;
}
int main(){
	io
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>vals[i];
	}
	for(int i = 1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		childs[a].push_back(b);
		childs[b].push_back(a);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i = 1;i<=n;i++)changeval(idx[i],vals[i],0,0,cnt);
	for(int i = 0;i<q;i++){
		int t;
		cin>>t;
		if(t == 1){
			int s,x;
			cin>>s>>x;
			changeval(idx[s],x,0,0,cnt);
		}
		else{
			int a,b;
			cin>>a>>b;
			cout<<getans(a,b)<<' ';
		}
	}
}

