#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define int ll
const int mxn = 1010;
const ll inf = 2e18;
int segtree[mxn*4+4];
void modify(int now,int l,int r,int p,int v){
	if(l==r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int dsu[mxn];
int cnt = -1;
vector<pll> g[mxn];
vector<pll> tree[mxn];
pll fa[mxn];
int idx[mxn],link_top[mxn],sz[mxn],son[mxn],dep[mxn];
int n,m;
int root(int now){
	while(now != dsu[now]){
		dsu[now] = dsu[dsu[now]];
		now = dsu[now];
	}
	return now;
}
void onion(int a,int b){
	int ra = root(a),rb = root(b);
	if(ra != rb)dsu[ra] = rb;
	return;
}
void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt.fs == fa[now].fs)continue;
		fa[nxt.fs] = {now,nxt.sc};
		dep[nxt.fs] = dep[now]+1;
		dfs1(nxt.fs);
		sz[now] += sz[nxt.fs];
		if(!son[now] || sz[nxt.fs] > sz[son[now]])son[now] = nxt.fs;
	}
	return;	
}
void dfs2(int now,int top){
	idx[now] = ++cnt;
	link_top[now] = top;
	modify(0,0,n,idx[now],fa[now].sc);
	if(son[now])dfs2(son[now],top);
	for(auto nxt:tree[now]){
		if(nxt.fs != fa[now].fs&&nxt.fs != son[now])dfs2(nxt.fs,nxt.fs);
	}
	return;
}
ll lca(int a,int b){
	ll big = 0;
	int ta = link_top[a],tb = link_top[b];
	while(ta != tb){
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
		}
		big = max(big,getval(0,0,n,idx[link_top[a]],idx[a]));
		a = fa[link_top[a]].fs;
		ta = link_top[a];
	}
	if(a != b){
		if(dep[a]>dep[b])swap(a,b);
		big = max(big,getval(0,0,n,idx[a],idx[b]));
	}
	return big;
}
main(){
	io
	int edges = 0;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a == b)continue;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	ll ans1 = 0,ans2 = inf;
	for(int i = 1;i<=n;i++)dsu[i] = i;
	priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
	for(int i = 1;i<=n;i++){
		for(auto &j:g[i]){
			pq.push({j.sc,{j.fs,i}});
		}
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(root(now.sc.fs) != root(now.sc.sc)){
			onion(now.sc.fs,now.sc.sc);
			tree[now.sc.fs].push_back({now.sc.sc,now.fs});
			tree[now.sc.sc].push_back({now.sc.fs,now.fs});
			ans1 += now.fs;
			edges++;
		}
	}
	dfs1(1);
	dfs2(1,1);
	set<pll> st;
	for(int i = 1;i<=n;i++){
		for(auto &j:tree[i]){
			st.insert({i,j.fs});
			st.insert({j.fs,i});
		}
	}
//	return 0;
	for(int i = 1;i<=n;i++){
		for(auto &j:g[i]){
			int a = j.fs,b = i;
			if(st.find({a,b}) != st.end())continue;
			ans2 = min(ans2,j.sc+ans1-lca(a,b));
//			cout<<a<<' '<<b<<' '<<j.sc<<' '<<lca(a,b)<<' '<<j.sc+ans1-lca(a,b)<<endl;
		}
	}
	if(edges != n-1)cout<<"-1 -1\n";
	else cout<<ans1<<' '<<(ans2 == inf||ans2<ans1?-1:ans2)<<'\n';
	return 0;	
}

