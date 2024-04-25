#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tiii tuple<int,int,int>


struct edge{
	int id,to,val;
	int from;
	edge(){id = to = val = from = 0;}
	edge(int ii,int ff,int tt,int vv):from(ff),id(ii),to(tt),val(vv){}
};
const int mxn = 2e5+10;
bitset<mxn> done;
vector<edge> paths[mxn],tree[mxn];
set<int> tedge;
vector<edge> edges;
map<int,vector<int>> mp[mxn];
map<pii,int> mp;
int segtree[mxn*4],sz[mxn],par[mxn],bs[mxn],link_top[mxn],dep[mxn],val[mxn],idx[mxn];
int n,m;
int ppp = 0;

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt.to == par[now])continue;
		par[nxt.to] = now;
		dep[nxt.to] = dep[now]+1;
		dfs1(nxt.to);
		if(bs[now] == 0||sz[bs[now]]<sz[nxt.to])bs[now] = nxt.to,val[nxt] = nxt.val;
		sz[now] += sz[nxt];
	}
	return;
}
void dfs2(int now,int top){
	link_top[now] = top;
	idx[now] = ++ppp;
	modify(0,0,mxn,idx[now],val[now]);
	if(bs[now]){
		dfs2(nxt,top);
	}
	for(auto nxt:tree[now]){
		if(nxt.to == par||nxt.to == bs[now])continue;
		dfs2(nxt.to,nxt.to);
	}
	return;
}
int lca(int a,int b){
	int ta = link_top[a],tb = link_top[b];
	int re = 0;
	while(ta != tb){
		if(dep[ta]<dep[tb])swap(ta,tb),swap(a,b);
		re = max(re,getval(0,0,mxn,idx[ta],idx[a]));
		a = par[ta];
		ta = link_top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	if(a != b){
		re = max(re,getval(0,0,mxn,dep[a]+1,dep[b]));
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	edges.push_back(edge());
	for(int i = 0;i<m;i++){
		edge tmp;
		cin>>tmp.from>>tmp.to>>tmp.val;
		tmp.id = i;
		edges.push_back(tmp);
		paths[tmp.from].push_back(tmp);
		mp[tmp.from][tmp.val].push_back(tmp.id);
		swap(tmp.from,tmp.to);
		edges.push_back(tmp);
		paths[tmp.from].push_back(tmp);
		mp[tmp.from][tmp.val].push_back(tmp.id);
	}
	priority_queue<tuple<int,int,int>,vector<tiii>,greater<tiii>> pq;
	pq.push(make_tuple(0,0,0));
	while(!pq.empty()){
		auto now = pq.top();
		int pos = get<2>(now);
		pq.pop();
		if(done[pos])continue;
		done[pos] = true;
		int eid = get<1>(now);
		if(eid != 0){
			tedge.insert(eid);
			tree[edges[eid].from].push_back(edges[eid]);
			swap(edges[eid].from,edges[eid].to);
			tree[edges.eid.from].push_back(edges[eid]);
		}
		for(auto nxt:paths[now]){
			if(done[nxt.to])continue;
			pq.push(make_tuple(nxt.val,nxt.id,nxt.to));
		}
	}
	par[1] = 1;
	dep[1] = 1;
	dfs1(1);
	dfs2(1,1);
}
