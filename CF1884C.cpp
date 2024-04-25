#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)
#define ls segtree[now].pl
#define rs segtree[now].pr

const int mxn  = 1e5+10;

struct node{
	int pl,pr;
	int big,tag,sm;
};


int ppp;
const int inf = 1e9+10;
pii arr[mxn];
node segtree[mxn*80];

inline int newnode(){
	ppp++;
	assert(ppp<mxn*80);
	segtree[ppp].sm = segtree[ppp].pl = segtree[ppp].pr = segtree[ppp].big = segtree[ppp].tag = 0;
	return ppp;
}

int modify(int now,int l,int r,int s,int e){
	if(!now)now = newnode();
	if(l>=s&&e>=r){
		segtree[now].tag ++;
		return now;
	}
	if(mid>=s)ls = modify(ls,l,mid,s,e);
	if(mid<e)rs = modify(rs,mid+1,r,s,e);
	segtree[now].big = max(segtree[ls].big+segtree[ls].tag,segtree[rs].big+segtree[rs].tag);
	segtree[now].sm = min(segtree[ls].sm+segtree[ls].tag,segtree[rs].sm+segtree[rs].tag);
	return now;
}

void solve(){
	ppp = 0;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	sort(arr,arr+n);
	int ans = 0;
	int rt = newnode();
	for(int i = n-1;i>=0;i--){
		modify(rt,1,m,arr[i].fs,arr[i].sc);
		ans = max(ans,segtree[rt].big-segtree[rt].sm);
	}
	ppp = 0;
	rt = newnode();
	sort(arr,arr+n,[](pii &a,pii &b){return a.sc<b.sc;});
	for(int i = 0;i<n;i++){
		modify(rt,1,m,arr[i].fs,arr[i].sc);
		ans = max(ans,segtree[rt].big-segtree[rt].sm);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
