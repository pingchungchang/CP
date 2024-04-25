#include <bits/stdc++.h>
using namespace std;

//#define ll long long
#define pii pll
#define pll pair<ll,ll>
#define ll int
#define fs first
#define sc second

const int mxn = 2e5+10;
const int inf = 1e9;
vector<pll> paths[mxn];
int bcc[mxn],low[mxn],id[mxn],cnt = 0,bccnt = 0;
vector<int> st;
int root[mxn];
bitset<mxn> done;

void tarjan(int now,int par){
	low[now] = id[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		if(!id[nxt.fs])tarjan(nxt.fs,now);
		low[now] = min(low[now],low[nxt.fs]);
	}
	if(low[now] == id[now]){
		bccnt++;
		while(st.back() != now){
			bcc[st.back()] = bccnt;
		}
		bcc[now] = bccnt;
		st.pop_back();
	}
	return;
}

struct SEG{
	pll segtree[mxn*4+4];
	SEG(){
		for(auto &i:segtree)i.fs = i.sc = 0;
	}
	void modify(int now,int l,int r,int s,int e,int v){
		if(l>=s&&e>=r){
			segtree[now].fs += v;
			return;
		}
		int mid = (l+r)>>1;
		if(mid>=s)modify(now*2+1,l,mid,s,e,v);
		if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
		segtree[now].sc = max(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
		return;
	}
	ll getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r){
			return segtree[now].fs+segtree[now].sc;
		}
		int mid = (l+r)>>1;
		if(mid>=e)return getval(now*2+1,l,mid,s,e)+segtree[now].fs;
		if(mid<s)return getval(now*2+2,mid+1,r,s,e)+segtree[now].fs;
		return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e))+segtree[now].fs;
	}
};

struct HLD{
	ll val[mxn],sz[mxn],dep[mxn],bs[mxn],par[mxn],idx[mxn],link_top[mxn];
	int pp;
	vector<int> tree[mxn];
	SEG segtree;
	HLD(){
	}
	void dfs1(int now){
		dep[now] = dep[par[now]]+1;
		sz[now] = 1;
		for(auto nxt:tree[now]){
			if(nxt == par[now])continue;
			par[nxt] = now;
			dfs1(nxt);
			if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
			sz[now] += sz[nxt];
		}
		return;
	}
	void dfs2(int now,int top){
		link_top[now] = top;
		idx[now] = pp++;
		segtree.modify(0,0,mxn,idx[now],idx[now],val[now]);
		if(bs[now])dfs2(bs[now],top);
		for(auto nxt:tree[now]){
			if(nxt == par[now]||nxt == bs[now])continue;
			dfs2(nxt,nxt);
		}
		return;
	}
	int lca(int a,int b){
		int ta = link_top[a],tb = link_top[b];
		int re = -inf;
		while(ta != tb){
			if(dep[ta]<dep[tb]){
				swap(ta,tb);
				swap(a,b);
			}
			re = max(re,getval(0,0,mxn,idx[ta],idx[a]));
			a = par[ta];
			ta = link_top[a];
		}
		if(dep[a]>dep[b])swap(a,b);
		if(a != b)re = max(re,getval(0,0,mxn,idx[a]+1,idx[b]));
		return re;
	}
};

HLD forest,htree;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	forest = HLD();
	htree = HLD();
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,b});
	}
	tarjan(1,1);
	for(int i = 0;i<=bccnt;i++)htree.val[i] = -inf;
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(bcc[i]>=bcc[nxt.fs])continue;
			bccnt++;
			htree.tree[i].push_back(bccnt);
			htree.tree[bccnt].push_back(i);
			htree.tree[nxt.fs].push_back(bccnt);
			htree.tree[bccnt].push_back(nxt.fs);
			htree.val[bccnt] = nxt.sc;
		}
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,1});
	root[1] = 1;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(done[now.sc])continue;
		done[now.sc] = true;
		for(auto nxt:paths[now.sc]){
			if(done[nxt.fs])continue;
			pq.push({nxt.sc,nxt.fs});
			if(bcc[nxt.fs] != bcc[now.sc])root[nxt.fs] = nxt.fs;
			else{
				cnt++;
				forest.tree[now.sc].push_back(cnt);
				forest.tree[nxt.fs].push_back(cnt);
				forest.tree[cnt].push_back(now.sc);
				forest.tree[cnt].push_back(nxt.fs);
				forest.val[cnt] = nxt.sc;
			}
		}
	}
	for(int i = 1;i<=n;i++)forest.val[i] = -inf;
	for(int i = 1;i<=n;i++)if(root[i] == i)forest.dfs1(i),forest.dfs2(i,i);
	for(int i = 1;i<=n;i++){
		if(!root[i]){
			int now = i;
			while(par[now]){
				now = forest.par[now];
				now = forest.link_top[now];
			}
			root[i] = now;
		}
	}
}
