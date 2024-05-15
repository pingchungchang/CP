#include "werewolf.h"
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
vector<int> ans;

struct SEG{
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)
	int seg[mxn*4];
	SEG(){
		memset(seg,-1,sizeof(seg));
	}
	void modify(int now,int l,int r,int p,int v){
		if(l==r){
			seg[now] = v;
			return;
		}
		if(mid>=p)modify(ls,l,mid,p,v);
		else modify(rs,mid+1,r,p,v);
		seg[now] = max(seg[ls],seg[rs]);
	}
	int getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r)return seg[now];
		if(mid>=e)return getval(ls,l,mid,s,e);
		else if(mid<s)return getval(rs,mid+1,r,s,e);
		return max(getval(ls,l,mid,s,e),getval(rs,mid+1,r,s,e));
	}
#undef ls
#undef rs
#undef mid
};

struct DSU{
	int mx[mxn],dsu[mxn],sz[mxn],mn[mxn];
	DSU(){}
	void init(int n){
		for(int i = 0;i<=n;i++){
			dsu[i] = mx[i] = mn[i] = i;
			sz[i] = 1;
		}
		return;
	}
	int root(int k){
		return k == dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(a == b)return;
		if(sz[a]<sz[b])swap(a,b);
		mx[a] = max(mx[a],mx[b]);
		mn[a] = min(mn[a],mn[b]);
		dsu[b] = a;
		sz[a] += sz[b];
		return;
	}
};

struct Tree{
	vector<int> tree[mxn];
	int par[mxn][20];
	pii eul[mxn];
	int ptr;
	Tree(){ptr = -1;}
	void add(int a,int b){
		tree[a].push_back(b);
	}
	void dfs(int now,int fa = 0){
		eul[now].fs = ++ptr;
		par[now][0] = fa;
		for(int i = 1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
		for(auto nxt:tree[now]){
			if(nxt == par[now][0])continue;
			dfs(nxt,now);
		}
		eul[now].sc = ptr;
		//cerr<<now<<":"<<eul[now].fs<<','<<eul[now].sc<<endl;
		return;
	}
};

struct D{//compare by x and y,data is a,b
	int x,y,a,b,c;
	D(int xx = 0,int yy = 0,int aa =0 ,int bb = 0,int cc = 0):x(xx),y(yy),a(aa),b(bb),c(cc){}
	bool operator<(D b)const{
		return x == b.x?y<b.y:x<b.x;
	}
};

vector<int> g[mxn];
D req[mxn];//s,e,l,r,id
int N,Q;
Tree mntr,mxtr;

namespace TREE{
	DSU dsu;
	void MAKE_MX(){
		dsu.init(N);
		for(int i = 0;i<N;i++){
			int now = i;
			for(auto nxt:g[now]){
				if(nxt>now||dsu.root(nxt) == dsu.root(now))continue;
				int tmp = dsu.mx[dsu.root(nxt)];
				mxtr.add(now,tmp);
				dsu.onion(now,nxt);
			}
		}
		mxtr.dfs(N-1,N-1);
	}
	void MAKE_MN(){
		dsu.init(N);
		for(int i = N-1;i>=0;i--){
			int now = i;
			for(auto nxt:g[now]){
				if(nxt<now||dsu.root(nxt) == dsu.root(now))continue;
				int tmp = dsu.mn[dsu.root(nxt)];
				mntr.add(now,tmp);
				dsu.onion(now,nxt);
			}
		}
		mntr.dfs(0,0);
		return;
	}
}

namespace SWEEP{
	vector<D> op;
	SEG seg;
	D trans(D now){
		int s = now.x,e = now.y,l = now.a,r = now.b,id = now.c;
		swap(s,e);
		if(s>r||e<l){
			ans[id] = 0;
			return D(-1);
		}
		for(int i = 19;i>=0;i--){
			if(mxtr.par[s][i] <= r)s = mxtr.par[s][i];
			if(mntr.par[e][i] >= l)e = mntr.par[e][i];
		}
		D re;
		re.x = mxtr.eul[s].sc,re.y = id;
		re.a = mntr.eul[e].fs,re.b = mntr.eul[e].sc;
		re.c = mxtr.eul[s].fs;
		return re;
	}

	void INIT(){
		for(int i = 0;i<N;i++){
			op.push_back(D(mxtr.eul[i].fs,-1,mntr.eul[i].fs));
		}
		for(int i = 0;i<Q;i++){
			auto tmp = trans(req[i]);
			if(tmp.x != -1)op.push_back(trans(req[i]));
			//cerr<<tmp.x<<' '<<tmp.y<<' '<<tmp.a<<' '<<tmp.b<<' '<<tmp.c<<endl;
		}
		return;
	}
	void GO(){
		sort(op.begin(),op.end());
		for(auto now:op){
			//cerr<<now.x<<','<<now.y<<' '<<now.a<<' '<<now.b<<' '<<now.c<<endl;
			if(now.y == -1){
				seg.modify(0,0,N-1,now.a,now.x);
			}
			else{
				int id = now.y;
				int s = now.a,e = now.b,up = now.c;
				if(seg.getval(0,0,N-1,s,e)>=up)ans[id] = 1;
				else ans[id] = 0;
			}
		}
	}
}

std::vector<int> check_validity(int NN, std::vector<int> X, std::vector<int> Y,
                                std::vector<int> S, std::vector<int> E,
                                std::vector<int> L, std::vector<int> R) {
	for(int i = 0;i<X.size();i++){
		int a = X[i],b = Y[i];
		g[a].push_back(b);
		g[b].push_back(a);
	}
	N = NN;
	Q = S.size();
	ans.resize(Q);
	for(int i = 0;i<Q;i++){
		req[i].x = S[i],req[i].y = E[i],req[i].a = L[i],req[i].b = R[i],req[i].c = i;
	}
	TREE::MAKE_MX();
	cerr<<"MX DONE!"<<endl;
	TREE::MAKE_MN();
	cerr<<"MN DONE!"<<endl;
	SWEEP::INIT();
	cerr<<"SWEEP INIT!"<<endl;
	SWEEP::GO();
	cerr<<"SWEEP DONE!"<<endl;
	return ans;
}
