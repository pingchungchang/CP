#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll mxn = 8e5+10;
ll segtree[mxn];
void modify(ll now,ll l,ll r,ll p,ll val){
	if(l == r){
		segtree[now] = val;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=p)modify(now*2+1,l,mid,p,val);
	else modify(now*2+2,mid+1,r,p,val);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
ll getval(ll now,ll l,ll r,ll val){
//	cout<<l<<' '<<r<<' '<<segtree[now]<<endl;
	if(l == r)return l;
	ll mid = (l+r)/2;
	if(segtree[now*2+2]>val)return getval(now*2+2,mid+1,r,val);
	else return getval(now*2+1,l,mid,val);
}
int main(){
	io
	ll n;
	cin>>n;
	ll h[n+1],p[n+1];
	for(int i = 1;i<=n;i++)cin>>h[i];
	for(int i = 1;i<=n;i++)cin>>p[i];
	modify(0,0,n,0,INT_MAX);
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ll tmp =  getval(0,0,n,h[i]+p[i]);
		ans += i-tmp-1;
//		cout<<tmp<<endl;
		modify(0,0,n,i,h[i]);
	}
	cout<<ans;
}

