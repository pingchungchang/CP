#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct node{
	ll val;
	ll tag;
	node(){
		val = 0;
		tag = 0;
	}
}node;
vector<node> segtree;

void maketree(int now,int s,int e,int pos,ll v){
	if(s==e){
		segtree[now].val = v;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=pos){
		maketree(now*2+1,s,mid,pos,v);
	}
	else if(mid+1<=pos){
		maketree(now*2+2,mid+1,e,pos,v);
	}
	segtree[now].val +=v;
	return;
}
void modify(int now,int s,int e,int l,int r,ll val){
	if(s==l&&e==r){
		segtree[now].tag += val;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=r){
		modify(now*2+1,s,mid,l,r,val);
	}
	else if(mid+1<=l){
		modify(now*2+2,mid+1,e,l,r,val);
	}
	else{
		modify(now*2+1,s,mid,l,mid,val);
		modify(now*2+2,mid+1,e,mid+1,r,val);
	}
	segtree[now].val += val*(r-l+1);
	return;
}

ll findval(int now,int s,int e,int l,int r){
	if(s==l&&e==r){
		return segtree[now].val+segtree[now].tag*(r-l+1);
	}
	int mid = (s+e)/2;
	if(mid>=r){
		return segtree[now].tag*(r-l+1)+findval(now*2+1,s,mid,l,r);
	}
	else if(mid+1<=l){
		return segtree[now].tag*(r-l+1)+findval(now*2+2,mid+1,e,l,r);
	}
	else{
		return segtree[now].tag*(r-l+1)+findval(now*2+1,s,mid,l,mid)+findval(now*2+2,mid+1,e,mid+1,r);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	segtree = vector<node>((int)(3.5*n),node());
	for(int i =0;i<n;i++){
		ll k;
		cin>>k;
		maketree(0,0,n-1,i,k);
	}
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
		int x;
		cin>>x;
		if(x==1){
			int l,r;
			ll v;
			cin>>l>>r>>v;
			l--,r--;
			modify(0,0,n-1,l,r,v);
		}
		else if(x==2){
			int l,r;
			cin>>l>>r;
			l--,r--;
			cout<<findval(0,0,n-1,l,r)<<'\n';
		}
	}
} 
