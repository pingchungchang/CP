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
	ll tag,val;
	node(){
		tag = val = 0;
	}
};
vector<node> segtree;

void push(ll now,ll l,ll r){
	if(segtree[now].tag == 0)return;
	segtree[now*2+1].tag ^= segtree[now].tag;
	segtree[now*2+2].tag ^= segtree[now].tag;
	ll mid = (r+l)/2;
	segtree[now*2+1].val = (mid-l+1)-segtree[now*2+1].val;
	segtree[now*2+2].val = (r-mid)-segtree[now*2+2].val;
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
	segtree[now].tag = 0;
}
void modify(ll now,ll l,ll r,ll s,ll e){
//	cout<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<endl;
	if(l>=s&&e>=r){
		segtree[now].tag^=1;
		segtree[now].val = (r-l+1)-segtree[now].val;
		return;
	}
	push(now,l,r);
	ll mid = (l+r)/2;
	if(mid>=s)modify(now*2+1,l,mid,s,e);
	if(mid<e)modify(now*2+2,mid+1,r,s,e);
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
	return;
}

ll getval(ll now,ll l,ll r,ll k){
	if(l == r){
		return l;
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(segtree[now*2+1].val>=k)return getval(now*2+1,l,mid,k);
	else return getval(now*2+2,mid+1,r,k-segtree[now*2+1].val);
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
			ll s,e;
			cin>>s>>e;
			modify(0,0,n-1,s,e-1);
		}
		else{
			ll k;
			cin>>k;
			cout<<getval(0,0,n-1,k+1)<<'\n';
		}
	}
}

