#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define ll int
struct Tree{
	ll par,link_top;
	ll sz,dep,bs;
	int idx;
	vector<pll> childs;
	Tree(){
		par = link_top = sz = dep = bs = 0;
		idx = 0;
	}
};
ll cc = 0;
const ll mxn = 2e5+10;
Tree tree[mxn];
pll segtree[mxn*4+4];
void push(int now,int l,int r){
	if(segtree[now].sc == -1)return;
	int mid = (l+r)>>1;
	segtree[now*2+1].sc = segtree[now].sc;
	segtree[now*2+2].sc = segtree[now].sc;
	segtree[now*2+1].fs = segtree[now].sc*(mid-l+1);
	segtree[now*2+2].fs = segtree[now].sc*(r-mid);
	segtree[now].sc = -1;
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs;
	int mid = (l+r)>>1;
	push(now,l,r);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
void modify(int now,int l,int r,int s,int e,ll val){
//	cout<<l<<' '<<r<<' '<<s<<' '<<e<<endl;
	if(l>=s&&e>=r){
		segtree[now].sc = val;
		segtree[now].fs = val*(r-l+1);
		return;
	}
	push(now,l,r);
	ll mid = (l+r)>>1;
	if(mid>=e)modify(now*2+1,l,mid,s,e,val);
	else if(mid<s)modify(now*2+2,mid+1,r,s,e,val);
	else{
		modify(now*2+1,l,mid,s,e,val);
		modify(now*2+2,mid+1,r,s,e,val);
	}
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+2].fs;
	return;
}
void dfs1(int now){
	tree[now].sz = 1;
	for(auto &i:tree[now].childs){
		int nxt = i.fs;
		if(nxt != tree[now].par){
			tree[nxt].par = now;
			tree[nxt].dep = tree[now].dep+1;
			dfs1(nxt);
			tree[now].sz += tree[nxt].sz;
			if(tree[now].bs == 0||tree[tree[now].bs].sz<tree[nxt].sz)tree[now].bs = nxt;
		}
	}
	return;
}
void dfs2(int now,int top){
	tree[now].idx = cc++;
	tree[now].link_top = top;
	if(tree[now].bs != 0)dfs2(tree[now].bs,top);
	for(auto &i:tree[now].childs){
		int nxt = i.fs;
		if(nxt == tree[now].bs)continue;
		if(nxt == tree[now].par){
			modify(0,0,mxn,tree[now].idx,tree[now].idx,i.sc);
			continue;
		}
		dfs2(nxt,nxt);
	}
	return;
}

ll lca(ll a,ll b){
	ll ans = 0;
	ll ta = tree[a].link_top,tb = tree[b].link_top;
	if(tree[ta].dep>tree[tb].dep){
		swap(ta,tb);
		swap(a,b);
	}
	while(ta != tb){
		ans += getval(0,0,mxn,tree[tb].idx,tree[b].idx);
		modify(0,0,mxn,tree[tb].idx,tree[b].idx,0LL);
		b = tree[tb].par;
		tb = tree[b].link_top;
		if(tree[ta].dep>tree[tb].dep){
			swap(ta,tb);
			swap(a,b);
		}
	}
	if(tree[a].idx == tree[b].idx)return ans;
	if(tree[a].idx>tree[b].idx)swap(a,b);
	if(tree[a].idx+1<=tree[b].idx)ans += getval(0,0,mxn,tree[a].idx+1,tree[b].idx);
	if(tree[a].idx+1<=tree[b].idx)modify(0,0,mxn,tree[a].idx+1,tree[b].idx,0);
	return ans;
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	for(auto &i:segtree)i = {0,-1};
	for(int i = 1;i<=n-1;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		tree[a].childs.push_back({b,w});
		tree[b].childs.push_back({a,w});
	}
//	modify(0,0,mxn,0,2,0);
//	return 0;
	dfs1(1);
	dfs2(1,1);
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<'\n';
	}
//	for(int i = 1;i<=n;i++)cout<<tree[i].idx<<' ';cout<<endl;
	return 0;
}

