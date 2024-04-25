#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> segtree;
void maketree(int pos,ll val,int now,int l,int r){
	if(l == r){
		segtree[now].first = val;
		segtree[now].second = max((ll)0,val);
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos){
		maketree(pos,val,now*2+1,l,mid);
	}
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now].first = segtree[now*2+1].first+segtree[now*2+2].first;
	segtree[now].second = max(segtree[now*2+1].second,segtree[now*2+1].first+segtree[now*2+2].second);
	return;
}
ll getsum(int s,int e,int now,int l,int r){
	if(s == l&&e == r){
		return segtree[now].first;
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getsum(s,e,now*2+1,l,mid);
	}
	else if(mid+1<=s){
		return getsum(s,e,now*2+2,mid+1,r);
	}
	else return getsum(s,mid,now*2+1,l,mid)+getsum(mid+1,e,now*2+2,mid+1,r);
}
ll getval(int s,int e,int now,int l,int r){
	if(s == l&&e == r){
		return segtree[now].second;
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid);
	}
	else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r);
	else{
		return max(getval(s,mid,now*2+1,l,mid),getsum(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	segtree = vector<pair<ll,ll>>(n*4,make_pair(0,0));
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
	for(int i = 0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
//		for(int i = 0;i<n*4;i++)cout<<segtree[i].second<<' ';		
		if(a == 1){
			maketree(b-1,(ll)c,0,0,n-1);
		}
		else{
			cout<<getval(b-1,c-1,0,0,n-1)<<'\n';
		}
	}
}
