#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct node{
	ll v;
	ll tag;
	node(){
		v = 0;
		tag = 0;
	}
}node;
vector<node> segtree;
void maketree(int s,int e,ll val,int now,int l,int r){
	if(l == s&&e == r){
		segtree[now].tag += val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=e){
		maketree(s,e,val,now*2+1,l,mid);
	}
	else if(mid+1<=s){
		maketree(s,e,val,now*2+2,mid+1,r);
	}
	else{
		maketree(s,mid,val,now*2+1,l,mid);
		maketree(mid+1,e,val,now*2+2,mid+1,r);
	}
	return;
}
ll getval(int pos,int now,int l,int r){
	if(l==r)return segtree[now].tag+segtree[now].v;
	int mid = (l+r)/2;
	if(pos>=mid+1)return segtree[now].tag+getval(pos,now*2+2,mid+1,r);
	else return segtree[now].tag+getval(pos,now*2+1,l,mid);
}
int main(){
	int n,m;
	cin>>n>>m;
	segtree = vector<node>(n*4,node());
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,i,k,0,0,n-1);
	}
	for(int i = 0;i<m;i++){
		int t;
		cin>>t;
		if(t==1){
			int a,b;
			ll c;
			cin>>a>>b>>c;
			maketree(a-1,b-1,c,0,0,n-1);
		}
		else{
			int k;
			cin>>k;
			cout<<getval(k-1,0,0,n-1)<<'\n';
		}
	}
}
