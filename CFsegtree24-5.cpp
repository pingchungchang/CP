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
	ll utag,dtag;
	node(){
		utag = 0;
		dtag = INT_MAX;
	}
};
vector<node> segtree;

void push(ll now,ll l,ll r){
	segtree[now*2+1].dtag = min(segtree[now].dtag,segtree[now*2+1].dtag);
	segtree[now*2+1].dtag = max(segtree[now*2+1].dtag,segtree[now].utag);
	segtree[now*2+1].utag = max(segtree[now].utag,segtree[now*2+1].utag);
	segtree[now*2+1].utag = min(segtree[now*2+1].utag,segtree[now].dtag);
	
	segtree[now*2+2].dtag = min(segtree[now].dtag,segtree[now*2+2].dtag);
	segtree[now*2+2].dtag = max(segtree[now*2+2].dtag,segtree[now].utag);
	segtree[now*2+2].utag = max(segtree[now].utag,segtree[now*2+2].utag);
	segtree[now*2+2].utag = min(segtree[now].dtag,segtree[now*2+2].utag);
	segtree[now].dtag = INT_MAX;segtree[now].utag = 0;
	return;
}
void modify(ll now,ll l,ll r,ll t,ll s,ll e,ll v){
	if(l>=s&&e>=r){
		if(t == 1){
			segtree[now].utag = max(segtree[now].utag,v);
			segtree[now].dtag = max(segtree[now].dtag,v);
		}
		else{
			segtree[now].dtag = min(segtree[now].dtag,v);
			segtree[now].utag = min(segtree[now].utag,v);
		}
		return;
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(mid>=s)modify(now*2+1,l,mid,t,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,t,s,e,v);
	return;
}
ll getval(ll now,ll l,ll r,ll p){
	if(l == r){
		return min(segtree[now].utag,segtree[now].dtag);
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(mid>=p)return getval(now*2+1,l,mid,p);
	else return getval(now*2+2,mid+1,r,p);
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4LL,node());
	while(q--){
		int t;
		ll s,e,v;
		cin>>t>>s>>e>>v;
		modify(0,0,n-1,t,s,e,v);
	}
	for(ll i = 0;i<n;i++)cout<<getval(0,0,n-1,i)<<'\n';
}

