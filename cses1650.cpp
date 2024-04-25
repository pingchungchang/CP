#include <bits/stdc++.h>
using namespace std;

int segtree[(int)1e5*8+5] = {};
void maketree(int pos,int val,int now,int l,int r){
	if(l==r){
		segtree[now] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos){
		maketree(pos,val,now*2+1,l,mid);
	}
	else{
		maketree(pos,val,now*2+2,mid+1,r);
	}
	segtree[now] = segtree[now*2+1]^segtree[now*2+2];
	return;
}
int findval(int s,int e,int now,int l,int r){
	if(s==l&&e==r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e){
		return findval(s,e,now*2+1,l,mid);
	}
	else if(mid+1<=s){
		return findval(s,e,now*2+2,mid+1,r);
	}
	else{
		return findval(s,mid,now*2+1,l,mid)^findval(mid+1,e,now*2+2,mid+1,r);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<findval(a-1,b-1,0,0,n-1)<<'\n';
	}
}
