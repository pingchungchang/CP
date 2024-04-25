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
#pragma GCC optimize("O3")
const ll mxn = 100+2e5;
pll segtree[mxn*4+4];
bool block = false;
bool flag = false;
void push(int now,int l,int r){
	if(segtree[now].sc == -1)return;
	if(now*2>=mxn*4){
		if(flag)cout<<"changeval";
		cout<<"ERROR"<<now<<' '<<l<<' '<<r<<endl;
		block = true;
		return;
	}
	int mid = (l+r)>>1;
	segtree[now*2+1].sc = segtree[now*2+2].sc = segtree[now].sc;
	segtree[now*2+1].fs = segtree[now*2+1].sc*(mid-l+1);
	segtree[now*2+2].fs = segtree[now*2+2].sc*(r-mid);
	segtree[now].sc = -1;
	return;
}
void changeval(int now,int l,int r,int s,int e,int val){
	if(s>e)return;
	if(l>r){
		cout<<now<<' '<<l<<' '<<r<<' '<<s<<' '<<e<<endl;
	}
	if(flag)cout<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<val<<endl;
	if(l>=s&&e>=r){
		segtree[now].sc = val;
		segtree[now].fs = val*(r-l+1);
		return;
	}
	push(now,l,r);
	int mid = (l+r)>>1;
	if(mid>=e)changeval(now*2+1,l,mid,s,e,val);
	else if(mid<s)changeval(now*2+2,mid+1,r,s,e,val);
	else{
		changeval(now*2+1,l,mid,s,e,val);
		changeval(now*2+2,mid+1,r,s,e,val);
	}
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+2].fs;
	return;
}
ll findone(int now,int l,int r,int p,int t){//t =1:l->r;t = 2:r->l
	if(r<p||segtree[now].fs == 0)return INT_MAX;
	if(l == r)return l;
	int mid = (l+r)/2;
	push(now,l,r);
	if(t == 2){
//		cout<<l<<' '<<r<<' '<<segtree[now].fs<<endl;
		if(segtree[now*2+2].fs != 0)return findone(now*2+2,mid+1,r,p,t);
		else return findone(now*2+1,l,mid,p,t);
	}
	if(mid<p)return findone(now*2+2,mid+1,r,p,t);
	ll re = findone(now*2+1,l,mid,p,t);
	if(re != INT_MAX)return re;
	re = min(re,findone(now*2+2,mid+1,r,p,t));
	return re;
}
ll bit[mxn+1];
void bmodify(ll s,ll e,ll val){
	s++,e++;
	e++;
	for(;s<mxn;s += s&-s)bit[s] += val;
	for(;e<mxn;e += e&-e)bit[e] -= val;
	return;
}
ll getval(ll p){
	p++;
	ll re = 0;
	if(p>=mxn){
		cout<<p<<"\n";
		return -1;
	}
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	io
	ll n,q;
	for(auto &i:segtree)i = {0,-1};
	cin>>n>>q;
	ll arr[n];
	ll vals[mxn];
	memset(vals,0LL,sizeof(vals));
	for(auto &i:arr){
		cin>>i;
		bmodify(i,i,1);
	}
	for(int i = 0;i<mxn-1;i++){
		if(getval(i) > 1){
			bmodify(i+1,i+1,getval(i)>>1);
			bmodify(i,i,-getval(i)/2*2);
		}
		changeval(0,0,mxn,i,i,getval(i));
	}
	while(q--){
		if(block)return 0;
		ll p,v;
		cin>>p>>v;
		p--;
//		cout<<arr[p]<<' '<<v<<":";
		if(getval(arr[p]) == 1){
			bmodify(arr[p],arr[p],-1);
			changeval(0,0,mxn,arr[p],arr[p],0);
			arr[p] = v;
			bmodify(arr[p],arr[p],1);
			changeval(0,0,mxn,arr[p],arr[p],getval(arr[p])+1);
		}
		else{
			ll le = findone(0,0,mxn,arr[p],0);
//			cout<<"; "<<le<<" ;";
			if(le == INT_MAX){
				cout<<"ERROR\n";
				return 0;
			}
			changeval(0,0,mxn,arr[p],le-1,1);
			changeval(0,0,mxn,le,le,0);
			changeval(0,0,mxn,v,v,getval(v)+1);
			bmodify(arr[p],le-1,1);
			bmodify(le,le,-1);
//			bmodify(arr[p],arr[p],-1);
			arr[p] = v;
			bmodify(v,v,1);
		}
//		for(auto &i:arr)cout<<i<<' ';cout<<',';
//		for(int i = 0;i<15;i++)cout<<getval(i)<<' ';
//		cout<<'\n';
		
		int pos = v;
		int s = pos,e = pos;
		while(getval(pos)>1){
			changeval(0,0,mxn,pos,pos,getval(pos)&1);
			changeval(0,0,mxn,pos+1,pos+1,getval(pos)>>1);
			bmodify(pos+1,pos+1,getval(pos)>>1);
			bmodify(pos,pos,-(getval(pos)/2*2));
			pos++; 
		}
		cout<<findone(0,0,mxn,0,2)<<'\n';
	}
}
/*
12 20
4 8 11 10 3 5 10 3 10 10 11 1
12 1
4 3
8 11
8 4
8 11
10 12
8 5
12 7
5 5
11 1
8 7
2 8
10 10
7 1
11 1
2 10
9 1
10 9
3 3
9 2
2 11
8 7
11 9
12 1
10 8
11 1
4 4
*/

