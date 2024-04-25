#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
vector<int> tree[mxn];
set<pii> st[mxn];
int arr[mxn];
int n;
pii eul[mxn];
pii segtree[mxn*4];
int pp;
ll ans = 0;

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	int mid = (l+r)>>1;
	int ls = now*2+1,rs = now*2+2;
	if(mid>=s)modify(ls,l,mid,s,e,v);
	if(mid<e)modify(rs,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[ls].fs+segtree[ls].sc,segtree[rs].fs+segtree[rs].sc);
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs+segtree[now].sc;
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e)+segtree[now].sc;
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e)+segtree[now].sc;
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e))+segtree[now].sc;
}

void dfs(int now){
	eul[now].fs = ++pp;
	for(auto nxt:tree[now]){
		dfs(nxt);
		if(st[nxt].size()>st[now].size()){
			swap(st[now],st[nxt]);
		}
		while(!st[nxt].empty()){
			st[now].insert(*st[nxt].begin());
			st[nxt].erase(st[nxt].begin());
		}
	}
	eul[now].sc = pp;
	auto it = st[now].lower_bound({arr[now],0});
	while(it != st[now].end()&&it->fs == arr[now]){
		int tmp = it->sc;
		st[now].erase(it);
		modify(0,1,n,eul[tmp].fs,eul[tmp].sc,-1);
		it = st[now].lower_bound({arr[now],0});
	}
	modify(0,1,n,eul[now].fs,eul[now].sc,1);
	st[now].insert({arr[now],now});
	pii big = make_pair(1,1);
	for(auto nxt:tree[now]){
		int val = getval(0,1,n,eul[nxt].fs,eul[nxt].sc);
		if(val>big.fs){
			swap(big.fs,big.sc);
			big.fs = val;
		}
		else if(val>big.sc)big.sc = val;
	}
	ans = max(ans,1ll*big.fs*big.sc);
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		st[i].clear();
	}
	for(int i = 0;i<=n*4;i++)segtree[i] = {0,0};
	pp = 0;
	cin>>n;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ans = 0;
	dfs(1);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
