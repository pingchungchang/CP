#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int tag;
	int val;
	node(){
		tag = 0;
		val =0;
	}
}node;
vector<node> segtree;

void modify(int now,int s,int e,int l,int r,int val){
	if(s==l&&e==r){
		segtree[now].tag += val;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=r){
		modify(now,s,mid,l,r,val);
		segtree[now].val = max(segtree[now*2+1].val+segtree[now*2+1].tag,segtree[now].val);
	}
	else if(mid+1>=l){
		modify(now,mid+1,e,l,r,val);
		segtree[now].val = max(segtree[now].val,segtree[now*2+2].val+segtree[now*2+2].tag);
	}
	else{
		modify(now,s,mid,l,mid,val);
		modify(now,mid+1,e,mid+1,r,val);
		segtree[now].val = max(segtree[now*2+1].val+segtree[now*2+1].tag,segtree[now*2+2].val+segtree[now*2+2].tag);
	}
	return;
}

int findval(int now,int s,int e,int l,int r){
	if(s==l&&e==r){
		return segtree[now].val+segtree[now].tag;
	}
	int mid = (s+e)/2;
	if(mid>=r){
		return segtree[now].tag+findval(now*2+1,s,mid,l,r);
	}
	if(mid+1<=l){
		return segtree[now].tag+findval(now*2+2,mid+1,e,l,r);
	}
	return segtree[now].tag+max(findval(now*2+1,s,mid,l,mid),findval(now*2+2,mid+1,e,mid+1,r));
}
void maketree(int val,int pos,int now,int s,int e){
	if(s==e){
		segtree[now].val = val;
		return;
	}
	int mid = (s+e)/2;
	if(pos<=mid){
		maketree(val,pos,now*2+1,s,mid);
	}
	else if(pos>mid){
		maketree(val,pos,now*2+2,mid+1,e);
	}
	segtree[now].val = max(segtree[now*2+1].val+segtree[now*2+1].tag,segtree[now*2+2].val+segtree[now*2+2].tag);
}
int main(){
	int n;
	cin>>n;
	segtree = vector<node>(4*n,node());
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		maketree(k,i,0,0,n-1);
	}
	for(int i =0;i<4*n;i++){
		cout<<segtree[i].val<<' ';
	}
	cout<<endl;
	int t;
	while(cin>>t){
		if(t==0)return 0;
		if(t==1){
			int l,r,val;
			cin>>l>>r>>val;
			l--,r--;
			modify(0,0,n-1,l,r,val);
		}
		else if(t == 2){
			int l,r;
			cin>>l>>r;
			l--,r--;
			for(int i =0;i<4*n;i++){
				cout<<segtree[i].val+segtree[i].tag<<' ';
			}
			cout<<endl;
			cout<<findval(0,0,n-1,l,r)<<'\n';
		}
	}
}
