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
	
	ll tag,val,sum;
	node(){
		tag = val = sum = 0;
	}
};
vector<node> segtree;
void push(ll now,ll l,ll r){
	segtree[now*2+1].tag += segtree[now].tag;
	segtree[now*2+2].tag += segtree[now].tag;
	segtree[now].tag = 0;
	ll mid = (l+r)/2;
	
	segtree[now].sum = segtree[now*2+1].tag*(mid-l+1)+segtree[now*2+1].sum+segtree[now*2+2].tag*(r-mid)+segtree[now*2+2].sum;
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+1].tag*(mid-l+2)*(mid-l+1)/2+segtree[now*2+2].val+segtree[now*2+2].tag*(r-mid+1)*(r-mid)/2;
	segtree[now].val += (segtree[now*2+2].sum+segtree[now*2+2].tag*(r-mid))*(mid-l+1);
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
	segtree[now].sum = segtree[now*2+1].tag*(mid-l+1)+segtree[now*2+1].sum+segtree[now*2+2].tag*(r-mid)+segtree[now*2+2].sum;
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+1].tag*(mid-l+2)*(mid-l+1)/2+segtree[now*2+2].val+segtree[now*2+2].tag*(r-mid+1)*(r-mid)/2;
	segtree[now].val += (segtree[now*2+2].sum+segtree[now*2+2].tag*(r-mid))*(mid-l+1);
	return;
}
ll getval(ll now,ll l,ll r,ll s,ll e){
	if(l>=s&&e>=r){
		ll re = segtree[now].val+segtree[now].tag*(r-l+1)*(r-l+2)/2;
		re += (segtree[now].sum+segtree[now].tag*(r-l+1))*(l-s);
		return re;
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
main(){
	io
	ll n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4+4,node());
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		addval(0,1,n,i,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			addval(0,1,n,s,e,v);
		}
		else{
			ll s,e;
			cin>>s>>e;
			cout<<getval(0,1,n,s,e)<<'\n';
		}
	}
	return 0;
}

