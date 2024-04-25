#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> segtree;


void addval(int now,int l,int r,int s,int e,ll v){
	if(l>=s&&e>=r){
		segtree[now] = max(segtree[now],v);
		return;
	}
	int mid = (l+r)/2;
	if(mid>=s)addval(now*2+1,l,mid,s,e,v);
	if(mid<e)addval(now*2+2,mid+1,r,s,e,v);
	return;
}
void push(int now){
	segtree[now*2+1] = max(segtree[now],segtree[now*2+1]);
	segtree[now*2+2] = max(segtree[now],segtree[now*2+2]);
	segtree[now] = 0;
	return;
}
int getval(int now,int l,int r,int p){
	if(l == r){
		return segtree[now];
	}
	int mid = (l+r)/2;
	push(now);
	if(mid>=p){
		return getval(now*2+1,l,mid,p);
	}
	else return getval(now*2+2,mid+1,r,p);
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<ll>(n*4,0LL);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int s,e,v;
			cin>>s>>e>>v;
			addval(0,0,n-1,s,e-1,v);
		}
		else{
			int p;
			cin>>p;
			cout<<getval(0,0,n-1,p)<<'\n';
		}
	}
}

