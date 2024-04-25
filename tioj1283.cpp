#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ll long long
const int mxn = 1e5+10;
pll a[mxn];
ll ans= 0;

struct node{
	ll x,y,id;
	node(){}
	node(int xx,int yy,int ii):x(xx),y(yy),id(ii){}
};
node segtree[mxn*4];
ll calc(pll x,node tt){
	pll y = {tt.x,tt.y};
	return (x.fs-y.fs)*(y.sc-x.sc);
}
void modify(int now,int l,int r,node v){
	if(l == r){
		if(calc(a[l],v)>calc(a[l],segtree[now]))segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(calc(a[mid],segtree[now])<calc(a[mid],v)){
		swap(segtree[now],v);
	}
	if(v.id>segtree[now].id){
		modify(now*2+2,mid+1,r,v);
	}
	else modify(now*2+1,l,mid,v);
	return;
}
ll getval(int now,int l,int r,int p){
	if(l == r)return calc(a[p],segtree[now]);
	int mid = (l+r)>>1;
	if(mid>=p)return max(getval(now*2+1,l,mid,p),calc(a[p],segtree[now]));
	else return max(getval(now*2+2,mid+1,r,p),calc(a[p],segtree[now]));
}
int main(){
	pll now = {0,0};
	int n;
	cin>>n;
	for(int i = 0;i<n/2;i++){
		int l,d;
		cin>>l>>d;
		now.fs += l;
		a[i] = now;
		now.sc += d;
	}
	n>>=1;
	now = {0,0};
	int m;
	cin>>m;
	for(int i = 0;i<m/2;i++){
		int l,d;
		cin>>d>>l;
		now.sc += d;
		modify(0,0,n,node(now.fs,now.sc,i+1));
		now.fs += l;
	}
	ll ans = 0;
	for(int i = 0;i<n;i++)ans= max(ans,getval(0,0,n-1,i));
	cout<<ans;
}