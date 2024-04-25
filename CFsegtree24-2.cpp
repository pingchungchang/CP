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
	ll atag,dtag;
	node(){
		atag = dtag = 0;
	}
};
vector<node> segtree;
void modify(ll now,ll l,ll r,ll s,ll e,ll a,ll d){
	if(s<=l&&e>=r){
		segtree[now].atag += a+(l-s)*d;
		segtree[now].dtag += d;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=s)modify(now*2+1,l,mid,s,e,a,d);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,a,d);
}
ll getval(ll now,ll l,ll r,ll p){
	if(l == r){
		return segtree[now].atag;
	}
	ll mid = (l+r)/2;
	if(mid>=p)return (segtree[now].atag == 0?0LL:segtree[now].atag+segtree[now].dtag*(p-l))+getval(now*2+1,l,mid,p);
	else return (segtree[now].atag == 0?0LL:segtree[now].atag+(p-l)*segtree[now].dtag)+getval(now*2+2,mid+1,r,p);
}
main(){
	io
	ll n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4+4,node());
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,a,d;
			cin>>s>>e>>a>>d;
			modify(0,1,n,s,e,a,d);
		}
		else{
			ll p;
			cin>>p;
			cout<<getval(0,1,n,p)<<'\n';
		}
	}
}

