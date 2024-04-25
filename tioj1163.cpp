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

const int mxn = 5e4+10;

struct edge{
	int s;
	int e;
	int val;
	edge(){}
	edge(int ss,int ee,int vv){
		s = ss,e =ee,val = vv;
	}
};
class Cmp{
	public:
		bool operator()(edge &a,edge&b){
			return a.val>b.val;
		}
};
vector<pii> paths[mxn];
vector<pii> tree[mxn];
int segtree[mxn*4+4];
int id[mxn];
bitset<mxn> goneto;
int cnt= 0;
void mst(int now){
	priority_queue<edge,vector<edge>,Cmp> pq;
	id[now] = cnt;
	for(auto &i:paths[now]){
		pq.push(edge(now,i.fs,i.sc));
	}
	while(!pq.empty()){
		auto tmp = pq.top();
		pq.pop();
		if(id[tmp.e])continue;
		else{
			tree[tmp.s].push_back({tmp.e,tmp.val});
			tree[tmp.e].push_back({tmp.s,tmp.val});
			id[tmp.e] = cnt;
			for(auto &i:paths[tmp.e]){
				if(id[i.fs])continue;
				pq.push(edge(tmp.e,i.fs,i.sc));
			}
		}
	}
	return;
}
int dep[mxn],link_top[mxn],fa[mxn],sz[mxn],ord[mxn];
pii bs[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}
int getval(int now,int l,int r,int s,int e){
//	cout<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<segtree[now]<<endl;
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
void dfs1(int now){
	goneto[now] = true;
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt.fs == fa[now])continue;
		fa[nxt.fs] = now;
		dep[nxt.fs] = dep[now]+1;
		dfs1(nxt.fs);
		sz[now] += sz[nxt.fs];
		if(bs[now].fs == 0||sz[bs[now].fs]<sz[nxt.fs])bs[now] = nxt;
	}
	return;
}
void dfs2(int now,int top,int val){
	link_top[now] = top;
	ord[now] = cnt++;
	modify(0,0,mxn,ord[now],val);
	if(bs[now].fs)dfs2(bs[now].fs,top,bs[now].sc);
	for(auto nxt:tree[now]){
		if(nxt.fs == fa[now]||nxt.fs == bs[now].fs)continue;
		dfs2(nxt.fs,nxt.fs,nxt.sc);
	}
	return;
}
int lca(int a,int b){
	int ta = link_top[a],tb = link_top[b];
	int re = 0;
	while(ta != tb){
//		cout<<a<<' '<<ta<<' '<<b<<' '<<tb<<endl;
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
		}
		re = max(re,getval(0,0,mxn,ord[ta],ord[a]));
		a = fa[ta];
		ta = link_top[a];
	}
	if(a == b)return re;
	else if(dep[a]>dep[b])swap(a,b);
//	cout<<getval(0,0,mxn,ord[b],ord[b])<<endl<<endl;
	return max(re,getval(0,0,mxn,ord[a]+1,ord[b]));
}
void dfs(int now,int par){
	cout<<par<<' '<<now<<' '<<ord[now]<<' '<<getval(0,0,mxn,ord[now],ord[now])<<endl;
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dfs(nxt.fs,now);
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	memset(segtree,INT_MAX,sizeof(segtree));
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	for(int i = 1;i<=n;i++){
		if(!id[i]){
			cnt++;
			mst(i);
		}
	}
	goneto.reset();
	cnt = 1;
	for(int i = 1;i<=n;i++){
		if(goneto[i])continue;
		dfs1(i);
		dfs2(i,i,INT_MAX);
	}
//	return 0;
	int q;
//	dfs(1,1);
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a == b){
			cout<<"0\n";
		}
		else if(id[a] != id[b]){
			cout<<"-1\n";
		}
		else cout<<lca(a,b)<<'\n';
	}
	return 0;
}

