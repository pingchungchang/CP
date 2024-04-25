#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1e5+10;
pll segtree[mxn*4+4];

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=e)modify(now*2+1,l,mid,s,e,v);
	else if(mid<s)modify(now*2+2,mid+1,r,s,e,v);
	else{
		modify(now*2+1,l,mid,s,e,v);
		modify(now*2+2,mid+1,r,s,e,v);
	}
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+1].sc*(mid-l+1)+segtree[now*2+2].fs+segtree[now*2+2].sc*(r-mid);
	return;
}
void push(int now,int l,int r){
	if(l == r)return;
	segtree[now*2+1].sc += segtree[now].sc;
	segtree[now*2+2].sc += segtree[now].sc;
	segtree[now].fs += segtree[now].sc*(r-l+1);
	segtree[now].sc = 0;
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs+segtree[now].sc*(r-l+1);
	int mid = (l+r)>>1;
	push(now,l,r);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		ll k;
		cin>>k;
		modify(0,0,mxn,i,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll a,b,c;
			cin>>a>>b>>c;
			modify(0,0,mxn,a,b,c);
		}
		else{
			ll a,b;
			cin>>a>>b;
			cout<<getval(0,0,mxn,a,b)<<'\n';
		}
	}
	return 0;
}

