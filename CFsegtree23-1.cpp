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
	ll sum,pre,suf;
	ll tag,val;
	node(){
		sum = pre = suf = 0;
		tag = INT_MAX;
		val = 0;
	}
};
vector<node> segtree;
void push(ll now,ll l,ll r){
	if(segtree[now].tag == INT_MAX)return;
	ll mid = (l+r)/2;
	segtree[now*2+1].tag = segtree[now*2+2].tag = segtree[now].tag;
	segtree[now*2+1].sum = segtree[now].tag*(mid-l+1);
	segtree[now*2+2].sum = segtree[now].tag*(r-mid);
	if(segtree[now].tag>0){
		segtree[now*2+1].pre = segtree[now*2+1].suf = segtree[now*2+1].val = segtree[now*2+1].sum;
		segtree[now*2+2].pre = segtree[now*2+2].suf = segtree[now*2+2].val = segtree[now*2+2].sum;
	}
	else{
		segtree[now*2+1].pre = segtree[now*2+2].pre = segtree[now*2+2].suf = segtree[now*2+1].suf = segtree[now*2+1].val = segtree[now*2+2].val = 0LL;
	}
	segtree[now].pre = max(segtree[now*2+1].pre,segtree[now*2+1].sum+segtree[now*2+2].pre);
	segtree[now].suf = max(segtree[now*2+2].suf,segtree[now*2+2].sum+segtree[now*2+1].suf);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	segtree[now].val = max(segtree[now*2+1].suf+segtree[now*2+2].pre,max(segtree[now*2+1].val,segtree[now*2+2].val));
	segtree[now].tag = INT_MAX;
	return;
}
void modify(ll now,ll l,ll r,ll s,ll e,ll v){
//	cout<<l<<' '<<r<<' '<<segtree[now].tag<<' '<<segtree[now].val<<'\n';
	if(s<=l&&e>=r){
		segtree[now].sum = v*(r-l+1);
		segtree[now].tag = v;
		if(v>=0){
			segtree[now].val = segtree[now].pre = segtree[now].suf = v*(r-l+1);
		}
		else segtree[now].val = segtree[now].pre = segtree[now].suf = 0LL;
		return;
	}
	push(now,l,r);
	ll mid = (l+r)/2;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].pre = max(segtree[now*2+1].pre,segtree[now*2+1].sum+segtree[now*2+2].pre);
	segtree[now].suf = max(segtree[now*2+2].suf,segtree[now*2+2].sum+segtree[now*2+1].suf);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	segtree[now].val = max(segtree[now*2+1].suf+segtree[now*2+2].pre,max(segtree[now*2+1].val,segtree[now*2+2].val));
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4,node());
	while(q--){
		ll s,e,v;
		cin>>s>>e>>v;
		modify(0,0,n-1,s,e-1,v);
		cout<<segtree[0].val<<'\n';
	}
}

