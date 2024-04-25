#include "bubblesort2.h"
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,avx2,sse4")
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5e5+10;
const ll inf = 1e9+10;



namespace BRUTE{

	void bubble(vector<int> &v){
		for(int i = 0;i+1<v.size();i++){
			if(v[i]>v[i+1])swap(v[i],v[i+1]);
		}
		return;
	}
	bool sorted(vector<int> &v){
		for(int i = 0;i+1<v.size();i++){
			if(v[i]>v[i+1])return false;
		}
		return true;
	}

	int getans(vector<int> &A){
		int re = 0;
		auto tmp = A;
		while(!sorted(tmp))re++,bubble(tmp);
		return re;
	}

}

struct SEG{
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)
	pll seg[mxn*8];
	SEG(){}
	void modify(int now,int l,int r,int s,int e,int v){
		if(l>=s&&e>=r){
			seg[now].sc += v;
			return;
		}
		if(mid>=s)modify(ls,l,mid,s,e,v);
		if(mid<e)modify(rs,mid+1,r,s,e,v);
		seg[now].fs = max(seg[ls].fs+seg[ls].sc,seg[rs].fs+seg[rs].sc);
	}
	int getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r)return seg[now].fs+seg[now].sc;
		if(mid>=e)return seg[now].sc+getval(ls,l,mid,s,e);
		else if(mid<s)return seg[now].sc+getval(rs,mid+1,r,s,e);
		else return max(getval(ls,l,mid,s,e),getval(rs,mid+1,r,s,e))+seg[now].sc;
	}
#undef ls
#undef rs
#undef mid
};

ll arr[mxn];
pll req[mxn];
int N,Q;
vector<ll> all;
SEG seg;
vector<int> ans;

void del(int p){
	seg.modify(0,0,all.size(),arr[p],arr[p],-p-inf);
	seg.modify(0,0,all.size(),arr[p]+1,all.size(),1);
	return;
}
void add(int p){
	seg.modify(0,0,all.size(),arr[p],arr[p],inf);
	seg.modify(0,0,all.size(),arr[p],arr[p],p);
	seg.modify(0,0,all.size(),arr[p]+1,all.size(),-1);
	return;
}

#define _all(T) T.begin(),T.end()
std::vector<int> countScans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
	all.push_back(inf*inf);
	all.push_back(0);
	N = A.size(),Q = X.size();
	for(int i = 0;i<N;i++)arr[i] = 1ll*A[i]*mxn+i,all.push_back(arr[i]);
	for(int i = 0;i<Q;i++){
		req[i].fs = X[i];
		req[i].sc = 1ll*V[i]*mxn+req[i].fs;
		all.push_back(req[i].sc);
	}
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 0;i<N;i++)arr[i] = lower_bound(_all(all),arr[i])-all.begin();
	for(int i = 0;i<Q;i++)req[i].sc = lower_bound(_all(all),req[i].sc)-all.begin();
	seg.modify(0,0,all.size(),0,all.size(),-inf);
	for(int i = 0;i<N;i++){
		seg.modify(0,0,all.size(),arr[i],arr[i],inf);
		seg.modify(0,0,all.size(),arr[i],arr[i],i);
		seg.modify(0,0,all.size(),arr[i]+1,all.size(),-1);
	}
	for(int i = 0;i<Q;i++){
		del(req[i].fs);
		arr[req[i].fs] = req[i].sc;
		add(req[i].fs);
		ans.push_back(seg.getval(0,0,all.size(),0,all.size()));
	}
	return ans;
}
