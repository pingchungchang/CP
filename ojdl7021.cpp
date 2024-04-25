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


const int mxn = 1e6+10;
pll segtree[mxn*4];
int arr[mxn];
int n,q;

void build(int now,int l,int r){
	if(l == r){
		segtree[now].fs = segtree[now].sc = arr[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	segtree[now].fs = segtree[ls].fs+segtree[rs].fs;
	segtree[now].sc = max(segtree[ls].sc,segtree[rs].sc);
}
void modify(int now,int l,int r,int s,int e,int k){
	if(l == r){
		segtree[now].fs = (segtree[now].sc%=k);
		return;
	}
	if(mid>=s&&segtree[ls].sc>=k)modify(ls,l,mid,s,e,k);
	if(mid<e&&segtree[rs].sc>=k)modify(rs,mid+1,r,s,e,k);
	segtree[now].fs = segtree[ls].fs+segtree[rs].fs;
	segtree[now].sc = max(segtree[ls].sc,segtree[rs].sc);
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	build(0,0,n-1);
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		if(t == 1){
			int k;
			cin>>k;
			modify(0,0,n-1,l,r,k);
		}
		else cout<<getval(0,0,n-1,l,r)<<'\n';
	}
}
