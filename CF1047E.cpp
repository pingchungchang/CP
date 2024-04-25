#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>> segtree;

void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now].first = val;
		segtree[now].second = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now].first = segtree[now*2+1].first;
	if(segtree[now*2+2].first != INT_MAX){
		segtree[now].first = min(segtree[now].first,segtree[now*2+2].first+(mid+1-l));
	}
	segtree[now].second = segtree[now*2+2].second;
	if(segtree[now*2+1].second != INT_MAX){
		segtree[now].second = min(segtree[now].second,segtree[now*2+1].second+(r-mid));
	}
	return;
}
int getval(int s,int e,int now,int l,int r, char t){
	if(s == l&&e == r){
		if(t == 'r')return segtree[now].second;
		else return segtree[now].first;
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid,t);
	}
	else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r,t);
	else{
		int lef = getval(s,mid,now*2+1,l,mid,t);
		int rig = getval(mid+1,e,now*2+2,mid+1,r,t);
		if(t == 'r'){
			if(lef != INT_MAX)lef += e-mid;
			return min(lef,rig);
		}
		else{
			if(rig != INT_MAX)rig += mid+1-s;
			return min(lef,rig);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	segtree = vector<pair<int,int>>(n*4,make_pair(INT_MAX,INT_MAX));
	vector<pair<int,int>> v(m);
	for(int i = 0;i<m;i++){
		cin>>v[i].first;
	}
	for(int i = 0;i<m;i++){
		cin>>v[i].second;
//		cout<<v[i].first<<' '<<v[i].second;
		maketree(v[i].first-1,v[i].second,0,0,n-1);
	}
	
	for(int i = 0;i<n;i++){
		int lef = getval(0,i,0,0,n-1,'r');
		int rig = getval(i,n-1,0,0,n-1,'l');
		cout<<min(lef,rig)<<' ';
	}
	cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
