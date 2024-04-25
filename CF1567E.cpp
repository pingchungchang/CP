#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct node{
	ll lval,rval;
	ll sum;
	node(){}
};
const int mxn = 2e5+10;
node segtree[mxn*4];
ll arr[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].sum = segtree[now].lval = segtree[now].rval = 1;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	if(arr[mid]<=arr[mid+1])segtree[now].sum += segtree[now*2+1].rval*segtree[now*2+2].lval;
	segtree[now].lval = segtree[now*2+1].lval;
	if(segtree[now].lval == mid-l+1&&arr[mid+1]>=arr[mid])segtree[now].lval += segtree[now*2+2].lval;
	segtree[now].rval = segtree[now*2+2].rval;
	if(segtree[now].rval == r-mid&&arr[mid+1]>=arr[mid])segtree[now].rval += segtree[now*2+1].rval;
	return;
}

node getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		auto a = getval(now*2+1,l,mid,s,e),b = getval(now*2+2,mid+1,r,s,e);
		a.sum += b.sum;
		if(arr[mid]<=arr[mid+1])a.sum += a.rval*b.lval;
		if(a.lval == mid-max(s,l)+1&&arr[mid]<=arr[mid+1])a.lval += b.lval;
		if(b.rval == min(r,e)-mid&&arr[mid]<=arr[mid+1])b.rval += a.rval;
		a.rval = b.rval;
		return a;
	}
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":"<<segtree[now].lval<<' '<<segtree[now].rval<<' '<<segtree[now].sum<<'\n';
	if(l == r)return;
	int mid = (l+r)>>1;
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		modify(0,1,n,i,arr[i]);
	}
	while(q--){
		int t;
		cin>>t;
		//dfs(0,1,n);
		if(t == 1){
			int p,v;
			cin>>p>>v;
			arr[p] = v;
			modify(0,1,n,p,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<getval(0,1,n,l,r).sum<<'\n';
		}
		//cout<<'\n';
	}
	return 0;
}
