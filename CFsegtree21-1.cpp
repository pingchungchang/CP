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

void addval(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now] += v;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=e)addval(now*2+1,l,mid,s,e,v);
	else if(mid<s)addval(now*2+2,mid+1,r,s,e,v);
	else{
		addval(now*2+1,l,mid,s,e,v);
		addval(now*2+2,mid+1,r,s,e,v);
	}
	return;
}
void push(int now,int l,int r){
	segtree[now*2+1]+=segtree[now];
	segtree[now*2+2]+=segtree[now];
	segtree[now] = 0;
	return;
}
ll getval(int now,int l,int r,int p){
	if(l == r){
		return segtree[now];
	}
	ll mid = (l+r)/2;
	push(now,l,r);
	if(mid>=p)return getval(now*2+1,l,mid,p);
	else return getval(now*2+2,mid+1,r,p);
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<ll>(n*4,0LL);
	while(q--){
		ll t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			addval(0,0,n-1,s,e-1,v);
		}
		else{
			ll p;
			cin>>p;
			cout<<getval(0,0,n-1,p)<<'\n';
		}
	}
}

