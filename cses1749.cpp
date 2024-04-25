#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int r;
	int v;
	int tag;
	node(){
		r = 0;
		v = 0;
		tag = 0;
	}
}node;
vector<node> segtree((int)1e5*8+5,node());
void maketree(int pos,int now,int l,int r){
	if(l==r){
		segtree[now].r = pos;
		segtree[now].v = pos;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,now*2+1,l,mid);
	else maketree(pos,now*2+2,mid+1,r);
	segtree[now].v = max(segtree[now*2+1].v,segtree[now*2+2].v);
	return;
}
int getval(int pos,int now,int l,int r){
	if(l==r){
		segtree[now].v = -999;
		segtree[now].tag = -999;
		return segtree[now].r;
	}
	int mid = (l+r)/2;
	int returns = 0;
	if(segtree[now*2+1].v+segtree[now*2+1].tag>=pos){
		segtree[now*2+2].tag -=1;
		returns =  getval(pos,now*2+1,l,mid);
	}
	else{
		returns =  getval(pos-segtree[now*2+2].tag,now*2+2,mid+1,r);
	}
	segtree[now].v = max(segtree[now*2+1].v+segtree[now*2+1].tag,segtree[now*2+2].v+segtree[now*2+2].tag);
	return returns;
	
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		maketree(i,0,0,n-1);
	}
	for(int i = 0;i<n-1;i++){
		int p;
		cin>>p;
		int pos = getval(p-1,0,0,n-1);
		cout<<v[pos]<<' ';
	}
	cout<<v[getval(0,0,0,n-1)];
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin>>n;
//	vector<int> v(n);
//	for(int i = 0;i<n;i++){
//		cin>>v[i];
//	}
//	for(int i = 0;i<n-1;i++){
//		int pos;
//		cin>>pos;
//		cout<<v[pos-1]<<' ';
//		v.erase(v.begin()+pos-1);
//	}
//	cout<<v[0];
//}
