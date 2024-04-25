#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

struct node{
	ll val;
	short tag;
	node(){
		val = tag = 0;
	}
};
const int bits = 20;
const ll mxn = 1e5+10;
node segtree[bits][mxn*3+4];
void push(node seg[],int now,int l,int r){
	if((seg[now].tag&1) == 0){
		seg[now].tag = 0;
		return;
	}
	else{
		int mid = (l+r)>>1;
		seg[now*2+1].tag ^=seg[now].tag;
		seg[now*2+2].tag ^=seg[now].tag;
		seg[now*2+1].val = (mid-l+1)-seg[now*2+1].val;
		seg[now*2+2].val = (r-mid)-seg[now*2+2].val;
		seg[now].tag = 0;
	}
	return;
}
void modify(node seg[],int now,int l,int r,int s,int e){
	if(l >=s&&e>=r){
		seg[now].tag^=1;
		seg[now].val = (r-l+1)-seg[now].val;
		return;
	}
	int mid = (l+r)>>1;
	push(seg,now,l,r);
	if(mid>=e)modify(seg,now*2+1,l,mid,s,e);
	else if(mid<s)modify(seg,now*2+2,mid+1,r,s,e);
	else{
		modify(seg,now*2+1,l,mid,s,e);
		modify(seg,now*2+2,mid+1,r,s,e);
	}
	seg[now].val = seg[now*2+1].val+seg[now*2+2].val;
	return;
}
ll getval(node seg[],int now,int l,int r,int s,int e){
	if(s<=l&&e>=r){
		return seg[now].val;
	}
	int mid = (l+r)>>1;
	push(seg,now,l,r);
	if(mid>=e)return getval(seg,now*2+1,l,mid,s,e);
	else if(mid<s)return getval(seg,now*2+2,mid+1,r,s,e);
	else return getval(seg,now*2+1,l,mid,s,e)+getval(seg,now*2+2,mid+1,r,s,e);
}
int main(){
	io
	ll n;
//	return 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		for(int j = 0;j<bits;j++){
			if(tmp&1){
				modify(segtree[j],0,0,mxn,i,i);
			}
			tmp>>=1;
		}
	}
	ll q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			long long re = 0;
			int s,e;
			cin>>s>>e;
			s--,e--;
			for(int j = 0;j<bits;j++){
				re += (1LL<<j)*getval(segtree[j],0,0,mxn,s,e);
			}
			cout<<re<<'\n';
		}
		else{
			int s,e,v;
			cin>>s>>e>>v;
			s--,e--;
			for(int j = 0;j<bits;j++){
				if(v&1)modify(segtree[j],0,0,mxn,s,e);
				v>>=1;
			}
		}
	}
	return 0;
}

