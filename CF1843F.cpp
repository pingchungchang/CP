#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
vector<int> tree[mxn];
int arr[mxn];
int idx[mxn],link_top[mxn],par[mxn],sz[mxn],bs[mxn],val[mxn],dep[mxn];
int n,cnt = 0;
vector<tuple<char,int,int,int>> req;

struct node{
	pii pref,suf,val;
	int sum;
	node(){
		pref = suf = val = {0,0};
		sum = 0;
	}
};
node segtree[mxn*4];

void dfs1(int now){
	sz[now] = 1;
	bs[now] = 0;
	for(auto nxt:tree[now]){
		dep[nxt] = dep[now]+1;
		par[nxt] = now;
		dfs1(nxt);
		if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
		sz[now] += sz[nxt];
	}
	return;
}

void dfs2(int now,int top){
	idx[now] = cnt++;
	link_top[now] = top;
	if(bs[now])dfs2(bs[now],top);
	for(auto nxt:tree[now]){
		if(nxt == bs[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}

node pull(node a,node b){
	node re;
	re.pref.fs = min(a.pref.fs,a.sum+b.pref.fs);
	re.pref.sc = max(a.pref.sc,a.sum+b.pref.sc);
	re.suf.fs = min(b.suf.fs,a.suf.fs+b.sum);
	re.suf.sc = max(b.suf.sc,a.suf.sc+b.sum);
	re.sum = a.sum+b.sum;
	re.val.fs = min({re.pref.fs,re.suf.fs,a.val.fs,b.val.fs,a.suf.fs+b.pref.fs});
	re.val.sc = max({re.suf.sc,re.pref.sc,a.val.sc,b.val.sc,a.suf.sc+b.pref.sc});
	return re;
}

void build(int now,int l,int r){
	if(l == r){
		segtree[now].pref.fs = segtree[now].suf.fs = min(0,arr[l]);
		segtree[now].pref.sc = segtree[now].suf.sc = max(0,arr[l]);
		segtree[now].sum = arr[l];
		segtree[now].val = make_pair(segtree[now].pref.fs,segtree[now].suf.sc);
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2]);
	return;
}

node getval(int now,int l,int r,int s,int e){
	if(s<1||e>n)exit(0);
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return pull(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

pii lca(int a,int b){
	int ta = link_top[a],tb = link_top[b];
	node na = node(),nb = node();
	while(ta != tb){
		//cout<<a<<','<<ta<<' '<<b<<' '<<tb<<' '<<'\n';
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
			swap(na,nb);
		}
		na = pull(getval(0,1,n,idx[ta],idx[a]),na);
		a = par[ta];
		ta = link_top[a];
	}
	//cout<<a<<','<<ta<<' '<<b<<' '<<tb<<' '<<'\n';
	if(dep[a]>dep[b]){
		swap(a,b);
		swap(na,nb);
	}
	nb = pull(getval(0,1,n,idx[a],idx[b]),nb);
	swap(na.suf.fs,na.pref.fs);
	swap(na.pref.sc,na.suf.sc);
	return pull(na,nb).val;
}

void solve(){
	req.clear();
	fill(idx,idx+n+1,0);fill(bs,bs+n+1,0);fill(link_top,link_top+n+1,0);fill(sz,sz+n+1,0);fill(par,par+n+1,0);
	fill(dep,dep+n+1,0);fill(arr,arr+n+1,0);fill(val,val+n+1,0);
	for(int i = 0;i<=n*4;i++)segtree[i] = node();
	for(int i = 0;i<=n;i++)tree[i].clear();
	cin>>n;
	val[1] = 1;
	cnt = 1;
	for(int i = 0;i<n;i++){
		char c;
		cin>>c;
		if(c == '+'){
			int a,b;
			cin>>a>>b;
			val[++cnt] = b;
			tree[a].push_back(cnt);
		}
		else{
			int a,b,cc;
			cin>>a>>b>>cc;
			req.push_back(make_tuple(c,a,b,cc));
		}
	}
	n = cnt;
	dep[1] = 1;
	par[1] = 1;
	dfs1(1);
	cnt = 1;
	dfs2(1,1);
	for(int i = 1;i<=n;i++)arr[idx[i]] = val[i];
	build(0,1,n);
	for(auto &i:req){
		auto tmp = lca(get<1>(i),get<2>(i));
		//cout<<get<1>(i)<<' '<<get<2>(i)<<":"<<tmp.fs<<' '<<tmp.sc<<'\n';
		if(tmp.sc>=get<3>(i)&&tmp.fs<=get<3>(i)){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}

