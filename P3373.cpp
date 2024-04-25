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
ll n,q,p;
const ll mxn = 1e5+10;
struct node{
	ll atag,mtag,val;
	node(){
		atag = val = 0;
		mtag = 1;
	}
};

node segtree[mxn*4+4];
void push(int now,int l,int r){
	int mid = (l+r)>>1;
	segtree[now*2+1].atag += segtree[now].atag*segtree[now].mtag%p;
	segtree[now*2+2].atag += segtree[now].atag*segtree[now].mtag%p;
	segtree[now*2+1].mtag *= segtree[now].mtag;segtree[now*2+2].mtag *= segtree[now].mtag;
	segtree[now].mtag = 1;
	segtree[now].atag = 0;
	segtree[now].val = segtree[now*2+1].val*segtree[now*2+1].mtag%p+segtree[now*2+2].val*segtree[now*2+2].mtag%p+
	segtree[now*2+1].atag*segtree[now*2+1].mtag%p+segtree[now*2+2].atag*segtree[now*2+2].mtag%p;
	return;
}
void addval(int now,int l,int r,int s,int e,ll v){
	if(s<=l&&e>=r){
		if(l == r)segtree[now].atag += v;
		else{
			push(now,l,r);
			segtree[now].atag += v;
		}
		return;
	}
	int mid = (l+r)>>1;
	push(now,l,r);
	if(mid>=e)addval(now*2+1,l,mid,s,e,v);
	else if(mid<s)addval(now*2+2,mid+1,r,s,e,v);
	else{
		addval(now*2+1,l,mid,s,e,v);
		addval(now*2+2,mid+1,r,s,e,v);
	}
	segtree[now].val = segtree[now*2+1].val*segtree[now*2+1].mtag%p+segtree[now*2+2].val*segtree[now*2+2].mtag%p+
	segtree[now*2+1].atag*segtree[now*2+1].mtag%p+segtree[now*2+2].atag*segtree[now*2+2].mtag%p;
	segtree[now].val %= p;
	return;
}


int main(){
	io
	cin>>n>>q>>p;
	for(int i = 1;i<=n;i++){
		ll k;
		cin>>k;
		addval(0,0,mxn,i,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			mul(0,0,mxn,s,e,v);
		}
		else if(t == 2){
			ll s,e,v;
			cin>>s>>e>>v;
			addval(0,0,mxn,s,e,v);
		}
		else{
			ll s,e;
			cin>>s>>e;
			cout<<getval(0,0,mxn,s,e)<<'\n';
		}
	}
	return 0;
}

