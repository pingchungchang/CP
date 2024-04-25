#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)
#define int ll

const int mxn = 2e5+10;
bitset<mxn> act;

struct node{
	ll cnt,sq,sum,tag;
	node(){}
};

node segtree[mxn*6];
ll q,d;

inline void pull(int now,int l,int r){
	segtree[now].sq = segtree[now].sum = segtree[now].cnt = 0;
	if(segtree[now*2+1].cnt){
		segtree[now].cnt += segtree[now*2+1].cnt;
		segtree[now].sum += segtree[now*2+1].sum;
		segtree[now].sq += segtree[now*2+1].sq;
	}
	if(segtree[now*2+2].cnt){
		segtree[now].cnt += segtree[now*2+2].cnt;
		segtree[now].sum += segtree[now*2+2].sum;
		segtree[now].sq += segtree[now*2+2].sq;
	}
	ll v = segtree[now].tag;
	segtree[now].sq = segtree[now].sq+segtree[now].sum*2*v+segtree[now].cnt*v*v;
	segtree[now].sum += segtree[now].cnt*v;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sq = segtree[now].sq+segtree[now].sum*2*v+segtree[now].cnt*v*v;
		segtree[now].sum += segtree[now].cnt*v;
		segtree[now].tag += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	pull(now,l,r);
}

void changeval(int now,int l,int r,int p){
	if(l == r){
		if(segtree[now].cnt){
			segtree[now].cnt = 0;
		}
		else{
			segtree[now].cnt = 1;
		}
		segtree[now].sq = segtree[now].tag*segtree[now].tag*segtree[now].cnt;
		segtree[now].sum = segtree[now].tag*segtree[now].cnt;
		assert(segtree[now].sq>=0&&segtree[now].sum>=0);
		return;
	}
	if(mid>=p)changeval(now*2+1,l,mid,p);
	else changeval(now*2+2,mid+1,r,p);
	pull(now,l,r);
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":"<<segtree[now].tag<<' '<<segtree[now].cnt<<' '<<segtree[now].sq<<endl;
	if(l == r)return;
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q>>d;
	while(q--){
		int k;
		cin>>k;
		changeval(0,0,mxn,k);
		if(act[k])modify(0,0,mxn,max(0ll,k-d),k-1,-1);
		else modify(0,0,mxn,max(0ll,k-d),k-1,1);
		//dfs(0,0,mxn);
		act[k] = (act[k]?0:1);
		cout<<(segtree[0].sq-segtree[0].sum)/2<<'\n';
	}
}

