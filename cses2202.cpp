#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> segtree;
void maketree(int pos,ll val,int now,int l,int r){
	if(l == r){
		segtree[now][0] = val;
		segtree[now][1] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos){
		maketree(pos,val,now*2+1,l,mid);
	}
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now][0] = min(segtree[now*2+1][0],segtree[now*2+2][0]+mid-l+1);
	segtree[now][1] = min(segtree[now*2+2][1],segtree[now*2+1][1]+r-mid);
//	cout<<l<<' '<<r<<' '<<segtree[now][0]<<' '<<segtree[now][1]<<'\n';
	return;
}
ll getval(int s,int e,int now,int l,int r,int t,int pos){
	if(s == l&&e == r){
		return segtree[now][t]+min(abs(pos-s),abs(pos-e));
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid,t,pos);
	}
	else if(mid+1<=s){
		return getval(s,e,now*2+2,mid+1,r,t,pos);
	}
	else{
		return min(getval(s,mid,now*2+1,l,mid,t,pos),getval(mid+1,e,now*2+2,mid+1,r,t,pos));
	}
}
void printall(int now,int l,int r){
	if(l == r){
		cout<<l<<' '<<r<<' '<<segtree[now][0]<<' '<<segtree[now][1]<<'\n';
		return;
	}
	int mid = (l+r)/2;
	cout<<l<<' '<<r<<' '<<segtree[now][0]<<' '<<segtree[now][1]<<'\n';	
	printall(now*2+1,l,mid);
	printall(now*2+2,mid+1,r);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	segtree = vector<vector<ll>>(n*4,vector<ll>(2,INT_MAX));
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
//	printall(0,0,n-1);
//	for(int i = 0;i<n*4;i++)cout<<segtree[i][0]<<' '<<segtree[i][1]<<',';
//	return 0;
	for(int i = 0;i<m;i++){
		int t;
		cin>>t;
		if(t == 1){
			int a;
			ll b;
			cin>>a>>b;
			maketree(a-1,b,0,0,n-1);
		}
		else{
			int k;
			cin>>k;
			cout<<min(getval(0,k-1,0,0,n-1,1,k-1),getval(k-1,n-1,0,0,n-1,0,k-1))<<'\n';
		}
	}
}
