#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
 
struct node{
	ll val,tag;
	node(){
		val = 0;
		tag = -1;
	}
};
vector<node>segtree;
void push(ll now,ll l,ll r){
	if(segtree[now].tag == -1)return;
	segtree[now*2+1].tag = segtree[now].tag;
	segtree[now*2+2].tag = segtree[now].tag;
	ll mid = (l+r)/2;
	segtree[now].val = segtree[now].tag*(r-l+1);
	segtree[now*2+1].val = segtree[now*2+1].tag*(mid-l+1);
	segtree[now*2+2].val = segtree[now*2+2].tag*(r-mid);
	segtree[now].tag = -1;
	return;
	
}
void modify(ll now,ll l,ll r,ll s,ll e,ll v){
	if(s<=l&&e>=r){
		segtree[now].tag = v;
		segtree[now].val = v*(r-l+1);
		return;
	}
	push(now,l,r);
	ll mid = (l+r)/2;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
}
ll getval(ll now,ll l,ll r,ll s,ll e){
	if(l>=s&&e>=r){
		return segtree[now].val;
	}
	push(now,l,r);
	ll mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
main(){
	io
	ll n,m;
	cin>>n>>m;
	segtree = vector<node>((n+1)*4,node());
	modify(0,0,n-1,0,n,1);
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(i<=n-1){
			cout<<i<<'\n';
		}
		else{
			if(a>b)swap(a,b); 
			modify(0,0,n-1,a-1,b-1,0);
			cout<<getval(0,0,n-1,0,n-1)<<'\n';
		}
	}
}
 
