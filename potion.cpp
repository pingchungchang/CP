#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
using namespace __gnu_pbds;
#pragma GCC target("avx2,popcnt")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

using namespace std;
const int inf = 1e9;
const int mxn = 2e5+10;
int arr[mxn];
int N,D,U;
pii ev[mxn];
vector<ll> segtree[mxn*4];

void init(int NN, int DD, int H[]) {
	N = NN,D = D;
	for(int i = 0;i<N;i++)arr[i] = H[i];
	return;
}

void modify(int now,int l,int r,int s,int e,int a,int b){
	if(l>=s&&e>=r){
		segtree[now].push_back(1ll*a*mxn+b);
		segtree[now].push_back(1ll*b*mxn+a);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,a,b);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,a,b);
	return;
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":";
	for(auto &i:segtree[now])cout<<i/mxn<<','<<i%mxn<<' ';cout<<endl;
	if(l == r)return;
	int mid = (l+r)>>1;
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
}

void curseChanges(int UU, int A[], int B[]) {
	U = UU;
	gp_hash_table<ll,int> mp;
	for(int i = 1;i<=U;i++){
		ev[i] = make_pair(A[i-1],B[i-1]);
		if(ev[i].fs>ev[i].sc)swap(ev[i].fs,ev[i].sc);
		ll tv = 1ll*ev[i].fs*mxn+ev[i].sc;
		if(mp.find(tv) != mp.end()){
			modify(0,1,U,mp[tv],i-1,ev[i].fs,ev[i].sc);
			mp.erase(tv);
		}
		else mp[tv] = i;
	}
	for(auto &i:mp){
		ll ta = i.fs/mxn,tb = i.fs-1ll*ta*mxn;
		modify(0,1,U,i.sc,U,ta,tb);
	}
	for(auto &i:segtree)sort(i.begin(),i.end());
	//dfs(0,1,U);
	return;
}

int buf[mxn];
int tmp[1010];
int pp = 0;
gp_hash_table<ll,int> done;

void getval(int now,int l,int r,int p,ll s,ll e){
	auto lit = lower_bound(segtree[now].begin(),segtree[now].end(),s);
	while(lit != segtree[now].end()&&*lit<e){
		buf[pp++] = *lit-s;
		lit++;
	}
	if(l == r)return;
	int mid = (l+r)>>1;
	if(mid>=p)getval(now*2+1,l,mid,p,s,e);
	else getval(now*2+2,mid+1,r,p,s,e);
}

int question(int x, int y, int t) {
	if(done.find(1ll*x*mxn*mxn+1ll*y*mxn+t) != done.end()){
		return done[1ll*x*mxn*mxn+1ll*y*mxn+t];
	}
	int pt = 0;
	pp = 0;
	getval(0,1,U,t,1ll*x*mxn,1ll*x*mxn+mxn-1);
	for(int i = 0;i<pp;i++)tmp[pt++] = arr[buf[i]]<<1;
	pp = 0;
	getval(0,1,U,t,1ll*y*mxn,1ll*y*mxn+mxn-1);
	for(int i = 0;i<pp;i++)tmp[pt++] = (arr[buf[i]]<<1)^1;
	sort(tmp,tmp+pt);
	int ans = 1e9;
	for(int i = 1;i<pt;i++){
		if((tmp[i]&1) != (tmp[i-1]&1))ans = min(ans,(tmp[i]>>1)-(tmp[i-1]>>1));
	}
	return (done[1ll*x*mxn*mxn+1ll*y*mxn+t] = done[1ll*y*mxn*mxn+1ll*x*mxn+t] = ans);
	/*
	for(int i = 0;i<n;i++)cout<<t1[i]<<' ';cout<<endl;
	for(int i = 0;i<m;i++)cout<<t2[i]<<' ';cout<<endl;
   */
}

