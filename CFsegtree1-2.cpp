#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll>segtree;

void maketree(ll now,ll l,ll r,ll p,ll v){
//	cout<<now<<' '<<l<<' '<<r<<' '<<p<<' '<<v<<endl;
	if(l == r){
		segtree[now] = v;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=p)maketree(now*2+1,l,mid,p,v);
	else maketree(now*2+2,mid+1,r,p,v);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
	return;
}
ll getval(ll now,ll l,ll r,ll s,ll e){
	if(l>=s&&e>=r)return segtree[now];
	ll mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return min(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	segtree = vector<ll>(n*4,INT_MAX);
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(0,0,n-1,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll p,v;
			cin>>p>>v;
			maketree(0,0,n-1,p,v);
		}
		else{
			ll s,e;
			cin>>s>>e;
			cout<<getval(0,0,n-1,s,e-1)<<'\n';
		}
//		for(int i = 0;i<n;i++)cout<<getval(0,0,n-1,i,i)<<' ';cout<<'\n';
	}
}

