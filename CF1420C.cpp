#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 1e18;
const int mxn = 3e5+10;

struct node{
	ll np,pp,nn,pn;
	node(){
		np = pp = nn = pn = -inf;
	}
};
node segtree[mxn*4];
ll arr[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].np = segtree[now].pn = -inf;
		segtree[now].nn = -v;
		segtree[now].pp = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].np = max(
		{segtree[now*2+1].np,segtree[now*2+2].np,
		segtree[now*2+1].nn+segtree[now*2+2].pp,
		segtree[now*2+1].np+segtree[now*2+2].np});
	segtree[now].nn = max(
		{segtree[now*2+1].nn,segtree[now*2+2].nn,
		segtree[now*2+1].nn+segtree[now*2+2].pn,
		segtree[now*2+1].np+segtree[now*2+2].nn});
	segtree[now].pp = max(
		{segtree[now*2+1].pp,segtree[now*2+2].pp,
		segtree[now*2+1].pn+segtree[now*2+2].pp,
		segtree[now*2+1].pp+segtree[now*2+2].np});
	segtree[now].pn = max(
		{segtree[now*2+1].pn,segtree[now*2+2].pn,
		segtree[now*2+1].pn+segtree[now*2+2].pn,
		segtree[now*2+1].pp+segtree[now*2+2].nn});
	return;
}

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		modify(0,1,n,i,arr[i]);
	}
	cout<<max({segtree[0].pn,segtree[0].pp})<<'\n';
	while(q--){
		int a,b;
		cin>>a>>b;
		swap(arr[a],arr[b]);
		modify(0,1,n,a,arr[a]);
		modify(0,1,n,b,arr[b]);
		cout<<max({segtree[0].pn,segtree[0].pp})<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
