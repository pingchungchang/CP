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
	ll val;
	ll tag;
	node(){
		val = tag = 0;
	}
};
vector<node> segtree;

void addval(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].tag += v;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=s)addval(now*2+1,l,mid,s,e,v);
	if(mid<e)addval(now*2+2,mid+1,r,s,e,v);
	segtree[now].val = min(segtree[now*2+1].val+segtree[now*2+1].tag,segtree[now*2+2].val+segtree[now*2+2].tag);
	return;
}
void push(int now){
	segtree[now*2+1].tag += segtree[now].tag;
	segtree[now*2+2].tag += segtree[now].tag;
	segtree[now].tag = 0;
	segtree[now].val = min(segtree[now*2+1].val+segtree[now*2+1].tag,segtree[now*2+2].val+segtree[now*2+2].tag);
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r){
		return segtree[now].val+segtree[now].tag;
	}
	push(now);
	int mid = (l+r)/2;	
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return min(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
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
			int s,e,v;
			cin>>s>>e>>v;
			addval(0,0,n-1,s,e-1,v);
		}
		else{
			int s,e;
			cin>>s>>e;
			cout<<getval(0,0,n-1,s,e-1)<<'\n';
		}
	}
}

