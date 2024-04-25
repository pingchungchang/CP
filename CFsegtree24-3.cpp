#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll cnt;
	ll tag;
	ll sum;
	ll lef,rig;
	node(){
		tag = -1;
		cnt = sum = lef = rig = 0;
	}
};
const ll mxn = 5e5+10;
vector<node> segtree;
void push(ll now,ll l,ll r){
	if(segtree[now].tag == -1)return;
	ll mid = (l+r)/2;
	segtree[now*2+1].tag = segtree[now*2+2].tag = segtree[now*2+1].lef = segtree[now*2+2].lef = segtree[now*2+1].rig = segtree[now*2+2].rig = segtree[now].tag;
	segtree[now*2+1].sum = segtree[now].tag*(mid-l+1);segtree[now*2+2].sum = segtree[now].tag*(r-mid);
	segtree[now*2+1].cnt = segtree[now].tag;segtree[now*2+2].cnt = segtree[now].tag;
//	segtree[now].cnt = segtree[now].tag;
//	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	segtree[now].tag = -1;
	return;
}
void modify(ll now,ll l,ll r,ll s,ll e,ll v){
	if(l >=s&&e>=r){
		segtree[now].tag = v;
		segtree[now].sum = v*(r-l+1);
		segtree[now].cnt = v;
		segtree[now].lef = segtree[now].rig = v;
		return;
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	segtree[now].cnt = segtree[now*2+1].cnt+segtree[now*2+2].cnt;
	if(segtree[now*2+1].rig == segtree[now*2+2].lef)segtree[now].cnt-=segtree[now*2+1].rig;
	segtree[now].lef = segtree[now*2+1].lef;
	segtree[now].rig = segtree[now*2+2].rig;
	return;
}
int main(){
	io
	ll q;
	cin>>q;
	segtree = vector<node>(mxn*8,node());
	while(q--){
		char c;
		ll s,e;
		cin>>c>>s>>e;
		e += s-1;
		modify(0,0,mxn*2,s+mxn,e+mxn,(c == 'W'?0LL:1LL));
		cout<<segtree[0].cnt<<' '<<segtree[0].sum<<'\n';
	}
}

