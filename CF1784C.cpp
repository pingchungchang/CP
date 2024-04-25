#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
#define int ll

const int mxn = 2e5+10;
pii segtree[mxn*4];
int arr[mxn];
int n;

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[ls].fs+segtree[ls].sc,segtree[rs].fs+segtree[rs].sc);
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs+segtree[now].sc;
	if(mid>=e)return getval(ls,l,mid,s,e)+segtree[now].sc;
	if(mid<s)return getval(rs,mid+1,r,s,e)+segtree[now].sc;
	return max(getval(ls,l,mid,s,e),getval(rs,mid+1,r,s,e))+segtree[now].sc;
}

pll getzero(int now,int l,int r,int s,int e){
	if(l == r){
		return make_pair(segtree[now].fs+segtree[now].sc,-l);
	}
	pll tmp = {-mxn,-mxn};
	if(segtree[ls].fs+segtree[ls].sc>segtree[rs].fs+segtree[rs].sc){
	}
}

void solve(){
	for(int i = 1;i<=n;i++){
		modify(0,1,n,i,i,-getval(0,1,n,i,i));
	}
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)modify(0,1,n,i,i,-i);
	ll sum = 0;
	for(int i = 1;i<=n;i++){
		if(getval(0,1,n,arr[i],n) < 0){
			sum += arr[i];
			modify(0,1,n,arr[i],n,1);
		}
		else{
			int p = getzero(0,1,n,arr[i],n);
			modify(0,1,n,p,n,-1);
			modify(0,1,n,arr[i],n,1);
			sum = sum-p+arr[i];
		}
		ll val = getval(0,1,n,n,n)+n;
		cout<<sum-val*(val+1)/2<<' ';
	}
	cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
