#include <bits/stdc++.h>
using namespace std;

int segtree[(int)1e5*8+5] = {};

void maketree(int i,int val,int now,int l,int r){
	if(l==r){
		segtree[now] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=i){
		maketree(i,val,now*2+1,l,mid);
	}
	else maketree(i,val,now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int change(int val,int now,int l,int r){
	if(val>segtree[now])return -1;
	if(l == r){
		segtree[now] -= val;
		return l;
	}
	int mid = (l+r)/2;
	int k = -1;
	if(segtree[now*2+1]>=val){
		k = change(val,now*2+1,l,mid);
	}
	else k = change(val,now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return k;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		int ans = change(k,0,0,n-1);
		cout<<ans+1<<' ';
	}
}
