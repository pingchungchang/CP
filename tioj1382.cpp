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

const int mxn = 2e5+10;
int segtree[mxn*4+4];
int n;
int ans[mxn];
void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] += v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
int getpos(int now,int l,int r,int val){
	if(l == r)return l;
	int mid = (l+r)>>1;
	if(segtree[now*2+1]>=val)return getpos(now*2+1,l,mid,val);
	else return getpos(now*2+2,mid+1,r,val-segtree[now*2+1]);
}
void solve(){
	memset(segtree,0,sizeof(segtree));
	for(int i = 0;i<n*2;i++)modify(0,0,mxn,i,1);
	int now = 0;
	int nn = n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		k--;
		k %= nn;
		int val = getval(0,0,mxn,0,now);
		int pos = getpos(0,0,mxn,val+k)%n;
		val = getval(0,0,mxn,0,pos);
//		cout<<now<<' '<<pos<<endl;
		pos %= n;
		ans[i] = pos;
		nn--;
		modify(0,0,mxn,pos,-1);
		modify(0,0,mxn,pos+n,-1);
		now = getpos(0,0,mxn,val)%n;
	}
//	cout<<'\n';
	for(int i = 0;i<n;i++)cout<<ans[i]+1<<' ';cout<<'\n';return;
}
int main(){
	io
	while(cin>>n)solve();
}

