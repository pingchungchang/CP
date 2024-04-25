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
	int big,small,tag;
	node(){
		big  = tag = 0;
		small = INT_MAX;
	}
};
vector<node> segtree;

void push(int now,int l,int r){
	if(segtree[now].tag == 0){
		segtree[now*2+1].tag = 0;
		segtree[now*2+2].tag = 0;
		segtree[now*2+1].small = segtree[now*2+2].small = INT_MAX;
		segtree[now*2+2].big = segtree[now*2+1].big = 0;
	}
	return;
}
void changeval(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].tag = 1;
		segtree[now].big = v;
		segtree[now].small = v;
		return;
	}
	int mid = (l+r)/2;
	push(now,l,r);
	if(mid>=p)changeval(now*2+1,l,mid,p,v);
	else changeval(now*2+2,mid+1,r,p,v);
	segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
	segtree[now].small = min(segtree[now*2+1].small,segtree[now*2+2].small);
	segtree[now].tag = segtree[now*2+1].tag+segtree[now*2+2].tag;
}
int getval(int now,int l,int r,int s,int e,int lim){
//	cout<<l<<' '<<r<<' '<<segtree[now].small<<' '<<s<<' '<<e<<' '<<lim<<'\n';
	if(segtree[now].tag == 0)return 0;
	if(segtree[now].small>lim)return 0;
	if(l>=s&&e>=r&&segtree[now].big<=lim){
		int k = segtree[now].tag;
		segtree[now].tag = 0;
		segtree[now].small = INT_MAX;
		segtree[now].big = 0;
		return k;
	}
	push(now,l,r);
	int mid = (l+r)/2;
	int re = 0;
	if(mid>=e)re = getval(now*2+1,l,mid,s,e,lim);
	else if(mid<s)re = getval(now*2+2,mid+1,r,s,e,lim);
	else re = getval(now*2+1,l,mid,s,e,lim)+getval(now*2+2,mid+1,r,s,e,lim);
	segtree[now].tag = segtree[now*2+1].tag+segtree[now*2+2].tag;
	segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
	segtree[now].small = min(segtree[now*2+1].small,segtree[now*2+2].small);
	return re;
}

void pv(int now,int l,int r){
	cout<<l<<' '<<r<<' '<<segtree[now].tag<<' '<<segtree[now].small<<' '<<segtree[now].big<<'\n';
	if(l == r)return;
	pv(now*2+1,l,(l+r)/2);
	pv(now*2+2,(l+r)/2+1,r);
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
			int p,v;
			cin>>p>>v;
			changeval(0,0,n-1,p,v);
//			pv(0,0,n-1);
//			cout<<'\n';
		}
		else{
			int s,e,lim;
			cin>>s>>e>>lim;
			cout<<getval(0,0,n-1,s,e-1,lim)<<'\n';
		}
	}
}

