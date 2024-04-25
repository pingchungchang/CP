#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define ll int
const ll mxn = 1e5+10;
ll segtree[(int)(mxn*8)];

void modify(int now,int l,int r,int p){
	if(l == r){
		segtree[now]++;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)modify(now*2+1,l,mid,p);
	else modify(now*2+2,mid+1,r,p);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
int main(){
	io
	int n;
	cin>>n;
	vector<pii> tmp(n*2);
	for(int i = 0;i<n*2;i++){
		cin>>tmp[i].fs;
		tmp[i].sc = i;
	}
	sort(_all(tmp));
	long long ans = 0;
	for(int i = 0;i<n*2;i+=2){
		ans +=getval(0,0,n*2-1,tmp[i].sc,tmp[i+1].sc);
		modify(0,0,n*2-1,tmp[i].sc);
		modify(0,0,n*2-1,tmp[i+1].sc);
	}
	cout<<ans;
	return 0;
}

