#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n,m;
ll segtree[(int)1e5*8+5];
void maketree(int pos,ll val,int now,int l,int r){
	if(l == r){
		segtree[now] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
ll getval(int s,int e,int now,int l,int r){
	if(s==l&&e==r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid);
	}
	else if(mid+1<=s){
		return getval(s,e,now*2+2,mid+1,r);
	}
	else{
		return getval(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r);
	}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
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
			int a,b;
			cin>>a>>b;
			cout<<getval(a-1,b-1,0,0,n-1)<<'\n';
		}
	}
}
