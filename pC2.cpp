#include <bits/stdc++.h>
using namespace std;

struct node{
	bool er;
	int s;
	int b;
	node(){
		s = INT_MAX;
		b = -1;
		er = false;
	}
};
vector<node> segtree;
vector<int> v;
int n,q;
void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now].b = val;
		segtree[now].s = val;
		segtree[now].er = false;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now].b = max(segtree[now*2+1].b,segtree[now*2+2].b);
	segtree[now].s = min(segtree[now*2+1].s,segtree[now*2+2].s);
	segtree[now].er = segtree[now*2+1].er|segtree[now*2+2].er;
	if(segtree[now*2+1].b>segtree[now*2+2].s)segtree[now].er = true;
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	v = vector<int>(n);
	segtree = vector<node>(n*4,node());
	for(int i = 0;i<n;i++){
		cin>>v[i];
		maketree(i,v[i],0,0,n-1);
	}
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--;
		v[a] = b;
		maketree(a,b,0,0,n-1);
		if(segtree[0].er == true){
			cout<<"No\n";
		}
		else cout<<"Yes\n";
	}
}
