#include <bits/stdc++.h>
using namespace std;

int segtree[8*(int)(1e5)+1] = {};
void maketree(int pos,int now,int l,int r){
	if(l == r){
		segtree[now] = 1;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,now*2+1,l,mid);
	else maketree(pos,now*2+2,mid+1,r);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
int getval(int s,int e,int now,int l,int r){
	if(s == l&&e == r){
		return segtree[now];
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid);
	}
	else if(mid+1<=s){
		return getval(s,e,now*2+2,mid+1,r);
	}
	else return getval(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r);
}
int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > v(n,make_pair(-1,-1));
	for(int i =0;i<2*n;i++){
		int k;
		cin>>k;
		if(v[k-1].first == -1)v[k-1].first = i;
		else v[k-1].second = i;
	}
	long long ans = 0;
	for(int i = 0;i<n;i++){
		ans += getval(v[i].first,v[i].second,0,0,2*n-1);
		maketree(v[i].first,0,0,2*n-1);
		maketree(v[i].second,0,0,2*n-1);
	}
	cout<<ans;
}
