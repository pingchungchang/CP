#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
vector<ll> segtree;

void addval(int s,int e,ll val,int now,int l,int r){
	if(s==l&&e==r){
		segtree[now] += val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=e){
		addval(s,e,val,now*2+1,l,mid);
		return;
	}
	else if(mid+1<=s){
		addval(s,e,val,now*2+2,mid+1,r);
		return;
	}
	else{
		addval(s,mid,val,now*2+1,l,mid);
		addval(mid+1,e,val,now*2+2,mid+1,r);
		return;
	}
}

ll getval(int pos,int now,int l,int r){
	if(l==r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=pos){
		return segtree[now]+getval(pos,now*2+1,l,mid);
	}
	else{
		return segtree[now]+getval(pos,now*2+2,mid+1,r);
	}
}
int main(){
	int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	v = vector<ll>(n,0);
	segtree = vector<ll>(4*n,0);
	for(int asd=0;asd<m;asd++){
		int s,e;
		ll val;
		cin>>s>>e>>val;
		s--;
		e--;
		addval(s,e,val,0,0,n-1);
	}
	for(int i =0;i<n;i++){
		v[i] = getval(i,0,0,n-1);
	}
	sort(v.begin(),v.end());
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	ll ans =0;
	for(int i =0;i<n;i++){
		ans += v[i]*pq.top();
		pq.pop();
	}
	cout<<ans;
}
