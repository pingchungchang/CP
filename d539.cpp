#include <bits/stdc++.h>
using namespace std;
void maketree(int val,int* segtree,int s,int e,int now,int num){
	if(s==e){
		segtree[now] = val;
		return;
	}
	int mid = (s+e)/2;
	if(mid>=num){
		maketree(val,segtree,s,mid,now*2+1,num);
	}
	else maketree(val,segtree,mid+1,e,now*2+2,num);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int search(int* segtree,int s,int e,int l,int r,int now){
	if(l==s&&r==e)return segtree[now];
	int mid = (s+e)/2;
	if(mid<l)return search(segtree,mid+1,e,l,r,now*2+2);
	else if(mid>=r)return search(segtree,s,mid,l,r,now*2+1);
	else{
		return max(search(segtree,s,mid,l,mid,now*2+1),search(segtree,mid+1,e,mid+1,r,2*now+2));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int segtree[(int)(3.5*n)]={0};//4 won't pass
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		maketree(k,(int*)segtree,0,n-1,0,i);
	}
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
		int s,e;
		cin>>s>>e;
		if(s>e)swap(s,e);
		s--;
		e--;
		cout<<search((int*) segtree,0,n-1,s,e,0)<<'\n';
	}
}
