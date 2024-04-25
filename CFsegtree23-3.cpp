#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll big;
	ll tag;
	node(){
		tag = big = 0;
	}
};
vector<node> segtree;

void push(ll now,ll l,ll r){
	segtree[now*2+1].tag += segtree[now].tag;
	segtree[now*2+2].tag += segtree[now].tag;
	segtree[now].tag = 0;
	segtree[now].big = max(segtree[now*2+1].tag+segtree[now*2+1].big,segtree[now*2+2].tag+segtree[now*2+2].big);
	return;
}
void addval(ll now,ll l,ll r,ll s,ll e,ll v){
	if(l>=s&&e>=r){
		segtree[now].tag += v;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=s)addval(now*2+1,l,mid,s,e,v);
	if(mid<e)addval(now*2+2,mid+1,r,s,e,v);
	segtree[now].big = max(segtree[now*2+1].tag+segtree[now*2+1].big,segtree[now*2+2].tag+segtree[now*2+2].big);
	return;
}
ll getval(ll now,ll l,ll r,ll p,ll v){
	if(l == r&&segtree[now].big+segtree[now].tag<v)return -1;
	else if(l == r)return l;
	ll mid = (l+r)/2;
	push(now,l,r);
	ll re = -1;
	if(segtree[now*2+1].big+segtree[now*2+1].tag>=v&&mid>=p)re = getval(now*2+1,l,mid,p,v);
	if(re != -1)return re;
	if(segtree[now*2+2].big+segtree[now*2+2].tag<v)return -1;
	else return getval(now*2+2,mid+1,r,p,v);
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4,node());
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			addval(0,0,n-1,s,e-1,v);
		}
		else{
			ll i,j;
			cin>>i>>j;
			cout<<getval(0,0,n-1,j,i)<<'\n';
		}
	}
}

