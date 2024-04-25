#include "secret.h"
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int mxn = 1010;
vector<int> pref[mxn*4],suf[mxn*4];
int arr[mxn];
int N;
map<pii,int> mp;

int ask(int a,int b){
	if(mp.find(pii(a,b)) != mp.end())return mp[pii(a,b)];
	else return mp[pii(a,b)] = Secret(a,b);
}

#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
void build(int now,int l,int r){
	if(l == r){
		pref[now].push_back(arr[l]);
		suf[now].push_back(arr[l]);
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	if(!now)return;
	pref[now] = pref[ls];
	for(int i = mid+1;i<=r;i++)pref[now].push_back(ask(pref[now].back(),arr[i]));
	suf[now] = suf[rs];
	reverse(suf[now].begin(),suf[now].end());
	for(int i = mid;i>l;i--)suf[now].push_back(ask(arr[i],suf[now].back()));
	suf[now].push_back(pref[now].back());
	reverse(suf[now].begin(),suf[now].end());
	//cout<<l<<' '<<r<<":";cout<<endl;for(auto &i:pref[now])cout<<i<<',';cout<<endl;for(auto &i:suf[now])cout<<i<<',';cout<<endl;
	return;
}

int getval(int now,int l,int r,int s,int e){
	if(l == r)return arr[l];
	if(mid>=s&&mid<e){
		return ask(suf[ls].end()[s-mid-1],pref[rs][e-mid-1]);
	}
	if(mid>=e)return getval(ls,l,mid,s,e);
	else return getval(rs,mid+1,r,s,e);
}
#undef ls
#undef rs
#undef mid

void Init(int NN, int A[]) {
	N = NN;
	for(int i = 0;i<N;i++)arr[i] = A[i];
	build(0,0,N-1);
	return;
}


int Query(int L, int R) {
	return getval(0,0,N-1,L,R);
}
