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


const int mxn = 2e5+10;
vector<int> tree[mxn];
bitset<mxn> del,vis,isfa;
int sz[mxn],dep[mxn];
pll segtree[mxn*4];
vector<pii> st;
int n,q;
pii eul[mxn];
int ans[mxn];
int ptr,nowsz,nowcen;
vector<int> req[mxn];
vector<int> block[mxn];

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[ls].fs+segtree[ls].sc,segtree[rs].fs+segtree[rs].sc);
	return;
}

int szdfs(int now,int par){
	vis[now] = true;
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		sz[now] += szdfs(nxt,now);
	}
	return sz[now];
}
int find_centroid(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		if(sz[nxt]>tar)return find_centroid(nxt,now,tar);
	}
	return now;
}

void dfs1(int now,int par){
	//cout<<now<<',';
	eul[now].fs = ++ptr;
	modify(0,0,nowsz,eul[now].fs,eul[now].fs,dep[now]);
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		dep[nxt] = dep[now]+1;
		dfs1(nxt,now);
	}
	eul[now].sc = ptr;
	return;
}

void dfs2(int now,int par,int head){
	for(auto &id:req[now]){
		assert(st.empty());
		if(head)modify(0,0,nowsz,eul[head].fs,eul[head].sc,-mxn);
		assert(head||now == nowcen);
		bool total = false;
		//cout<<now<<' '<<id<<":";
		for(auto &j:block[id]){
			if(!vis[j])continue;
			//cout<<eul[j].fs<<','<<eul[j].sc<<' ';
			if(isfa[j])total = true;
			else modify(0,0,nowsz,eul[j].fs,eul[j].sc,-mxn);
		}
		if(!total)ans[id] = max(1ll*ans[id],segtree[0].fs+segtree[0].sc+dep[now]);
		//cout<<segtree[0]<<endl;
		for(auto &j:block[id]){
			if(!vis[j])continue;
			if(isfa[j]);
			else modify(0,0,nowsz,eul[j].fs,eul[j].sc,mxn);
		}
		if(head)modify(0,0,nowsz,eul[head].fs,eul[head].sc,mxn);
	}
	isfa[now] = true;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		dfs2(nxt,now,(head?head:nxt));
	}
	isfa[now] = false;
	return;
}


void cdfs(int now,int par){
	vis[now] = false,sz[now] = 0,dep[now] = 0;
	eul[now].fs = eul[now].sc = 0;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		cdfs(nxt,now);
	}
	return;
}

void cendfs(int now){
	nowsz = szdfs(now,now);
	nowcen = (now = find_centroid(now,now,(nowsz-1)>>1));
	ptr = 0;
	dep[now] = 0;
	//cout<<now<<":"<<segtree[0]<<endl;
	//fill(segtree,segtree+nowsz*4+4,0);
	for(int i = 0;i<nowsz*4+4;i++)segtree[i] = make_pair(0,0);
	dfs1(now,now);
    assert(ptr==nowsz);
	//cout<<endl;
	dfs2(now,now,0);

	assert(st.empty());
	cdfs(now,now);
	del[now] = true;
	for(auto nxt:tree[now]){
		if(del[nxt])continue;
		cendfs(nxt);
	}
	return;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=q;i++){
		int rt;
		cin>>rt;
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			block[i].push_back(tmp);
		}
		req[rt].push_back(i);
	}
	cendfs(1);
	//cout<<endl;
	for(int i = 1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
