#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
#define pii pair<int,int>
#define fs first
#define sc second
#define ll long long

const int mxn = 2e5+10;

int nid[mxn*100],val[mxn*100];
int vcnt = 0;

struct node{
	int head;
	int pl,pr;
};

int add(int now,int v){
	vcnt++;
	nid[vcnt] = now;
	val[vcnt] = v;
	return vcnt;
}

struct SEG{
#define mid ((l+r)>>1)
#define ls seg[now].pl
#define rs seg[now].pr
	node seg[mxn*50];
	int ppp = 0;
	SEG(){}
	int newnode(){
		return ++ppp;
	}
	int modify(int now,int l,int r,int s,int e,int v){
		if(!now)now = newnode();
		if(l>=s&&e>=r){
			seg[now].head = add(seg[now].head,v);
			return now;
		}
		if(mid>=s)ls = modify(ls,l,mid,s,e,v);
		if(mid<e)rs = modify(rs,mid+1,r,s,e,v);
		return now;
	}
	int re[mxn],ptr = 0;
	void addv(int v){
		re[ptr++] = v;
		return;
	}
	void getval(int now,int l,int r,int p){
		if(!now)return;
		for(int i = seg[now].head;i;i = nid[i])addv(val[i]);
		if(l == r)return;
		if(mid>=p)getval(ls,l,mid,p);
		else getval(rs,mid+1,r,p);
		return;
	}
#undef ls
#undef rs
#undef mid
};

SEG seg;
int arr[mxn],N,D;
int rt[mxn];

void init(int NN, int DD, int H[]) {
	N = NN,D = DD;
	for(int i = 0;i<N;i++){
		arr[i] = H[i];
	}
	return;
}

void curseChanges(int U, int A[], int B[]) {
	map<ll,int> mp;
	for(int i = 0;i<U;i++){
		pii p = {A[i],B[i]};
		if(p.fs>p.sc)swap(p.fs,p.sc);
		ll h = 1ll*p.fs*mxn+p.sc;
		if(mp.find(h) != mp.end()){
			rt[p.fs] = seg.modify(rt[p.fs],0,mxn-10,mp[h]+1,i,arr[p.sc]);
			rt[p.sc] = seg.modify(rt[p.sc],0,mxn-10,mp[h]+1,i,arr[p.fs]);
			mp.erase(h);
		}
		else{
			mp[h] = i;
		}
	}
	for(auto &i:mp){
		pii p = pii(i.fs/mxn,i.fs%mxn);
		rt[p.fs] = seg.modify(rt[p.fs],0,mxn-10,i.sc+1,mxn-10,arr[p.sc]);
		rt[p.sc] = seg.modify(rt[p.sc],0,mxn-10,i.sc+1,mxn-10,arr[p.fs]);
	}
	return;
}

unordered_map<ll,int> done;

int question(int x, int y, int v) {
	if(done.find(1ll*x*mxn*mxn+1ll*y*mxn+v) != done.end())return done[1ll*x*mxn*mxn+1ll*y*mxn+v];
	seg.ptr = 0;seg.getval(rt[x],0,mxn-10,v);
	vector<int> ta;
	for(int i = 0;i<seg.ptr;i++){
		ta.push_back(seg.re[i]);
	}
	seg.ptr = 0;seg.getval(rt[y],0,mxn-10,v);
	vector<int> tb;
	for(int i = 0;i<seg.ptr;i++){
		tb.push_back(seg.re[i]);
	}
	sort(ta.begin(),ta.end());
	sort(tb.begin(),tb.end());
	int pt = 0;
	int ans = 1e9;
	for(auto &i:ta){
		while(pt != tb.size()&&tb[pt]<i)pt++;
		if(pt != tb.size())ans = min(ans,abs(i-tb[pt]));
		if(pt-1>=0)ans = min(ans,abs(i-tb[pt-1]));
	}
	return done[1ll*x*mxn*mxn+1ll*y*mxn+v] = done[1ll*x*mxn*mxn+1ll*y*mxn+v] = ans;
}
