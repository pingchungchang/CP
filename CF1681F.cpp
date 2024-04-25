#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2

const int mxn = 5e5+10;

struct Edge{
	int a,b,val;
	Edge(){}
};

pii segtree[mxn*4];
pii tag[mxn*4];
pii eul[mxn];
vector<int> tree[mxn];
vector<pii> edges[mxn];
int n,dep[mxn],sz[mxn];
ll ans = 0;
int ppp;

void dfs(int now,int par){
	eul[now].fs = ++ppp;
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	eul[now].sc = ppp;
}

inline void push(int now){
	if(!tag[now].fs)return;
	segtree[now] = segtree[ls] = segtree[rs] = tag[ls] = tag[rs] = tag[now];
	tag[now] = {0,0};
	return;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		tag[now] = segtree[now] = make_pair(dep[v],v);
		return;
	}
	push(now);
	if(mid>=s)modify(ls,l,mid,s,e,v);
	if(mid<e)modify(rs,mid+1,r,s,e,v);
	segtree[now] = max(segtree[ls],segtree[rs]);
	return;
}
pii getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	push(now);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

vector<pll> change;
vector<int> tree2[mxn];
vector<int> used;

ll dfs2(int now,int par){
	ll sum = 0;
	ll re = 0;
	for(auto nxt:tree2[now]){
		sum += sz[nxt];
		if(nxt != par)re += dfs2(nxt,now);
	}
	re = re+sum*sz[now];
	return re;
}

inline ll calc(int col){
	modify(0,0,ppp,0,ppp,1);
	for(auto &i:edges[col]){
		auto a = i.fs,b = i.sc,rt = getval(0,0,ppp,eul[a].fs,eul[a].fs).sc;
		change.push_back({rt,sz[rt]});
		sz[rt] -= sz[b];
		used.push_back(rt);
		used.push_back(b);
		tree2[rt].push_back(b);
		tree2[b].push_back(rt);
		modify(0,0,ppp,eul[b].fs,eul[b].sc,b);
	}
	ll re = dfs2(1,1)/2;
	while(!change.empty()){
		auto now = change.back();
		change.pop_back();
		sz[now.fs] = now.sc;
	}
	for(auto &i:used)tree2[i].clear();
	used.clear();
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		Edge tmp;
		cin>>tmp.a>>tmp.b>>tmp.val;
		tree[tmp.a].push_back(tmp.b);
		tree[tmp.b].push_back(tmp.a);
		edges[tmp.val].push_back({tmp.a,tmp.b});
	}
	dep[1] = 1;
	dfs(1,1);

	//for(int i = 1;i<=n;i++)cout<<eul[i].fs<<':'<<eul[i].sc<<endl;
	for(int i = 1;i<=n;i++){
		for(auto &j:edges[i])if(dep[j.fs]>dep[j.sc])swap(j.fs,j.sc);
		sort(edges[i].begin(),edges[i].end(),[](pii &a,pii &b){return dep[a.fs]<dep[b.fs];});
		ll re = calc(i);
		//cout<<i<<":"<<re<<endl;
		ans += re;
	}
	cout<<ans;
}
