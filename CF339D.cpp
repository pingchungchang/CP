#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int orxor;
	int val;
	node(){
		orxor = 0;
		val =0;
	}
}node;
vector<node> segtree;
int n;
void maketree(int now,int s,int e,int val,int pos){
	if(s == e){
		segtree[now].val = val;
		segtree[now].orxor = -1;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=pos){
		maketree(now*2+1,s,mid,val,pos);
		segtree[now].orxor = 0-segtree[now*2+1].orxor;
	}
	else{
		maketree(now*2+2,mid+1,e,val,pos);
		segtree[now].orxor = 0-segtree[now*2+2].orxor;
	}
	if(segtree[now].orxor == -1){
		segtree[now].val = segtree[now*2+1].val^segtree[now*2+2].val;
	}
	else segtree[now].val = segtree[now*2+1].val|segtree[now*2+2].val;
	return;
}
void modify(int now,int s,int e,int pos,int v){
	if(s == e){
		segtree[now].val = v;
	//	cout<<segtree[s].val;
		//for(int i =0;i<4*n;i++)cout<<segtree[i].val<<' ';
		//cout<<'s'<<now<<endl;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=pos){
		modify(now*2+1,s,mid,pos,v);
	}
	else modify(now*2+2,mid+1,e,pos,v);
	
	if(segtree[now].orxor == -1){
		segtree[now].val = segtree[now*2+1].val^segtree[now*2+2].val;
	}
	else segtree[now].val = segtree[now*2+1].val|segtree[now*2+2].val;
	//for(int i =0;i<4*n;i++)cout<<segtree[i].val<<' ';
	//cout<<endl;
	return;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>n>>m;
	n = 1<<n;
	segtree = vector<node>(n*4,node());
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		maketree(0,0,n-1,k,i);
	}
	for(int i =0;i<m;i++){
		int pos,v;
		cin>>pos>>v;
		pos--;
		modify(0,0,n-1,pos,v);
		//cout<<pos<<v;
		cout<<segtree[0].val<<'\n';
	}
}
