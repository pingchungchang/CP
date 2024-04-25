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

const ll mxn = 3e5+10;

ll segtree[mxn*4+5];
void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = max(segtree[now],1LL*v);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int main(){
	io
	ll n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		modify(0,0,mxn,tmp,getval(0,0,mxn,tmp-k,tmp+k)+1);
	}
	cout<<segtree[0];
}

