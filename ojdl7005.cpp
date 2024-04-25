#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> segtree;
ll n,q;

ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void maketree(ll p,ll v,ll now,ll l,ll r){
	if(l == r){
		segtree[now] = v;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=p)maketree(p,v,now*2+1,l,mid);
	else maketree(p,v,now*2+2,mid+1,r);
	segtree[now] = gcd(segtree[now*2+1],segtree[now*2+2]);
	return;
}
ll getval(ll s,ll e,ll now,ll l,ll r){
	if(s<=l&&e>=r)return segtree[now];
	ll mid = (l+r)/2;
	if(mid>=e)return getval(s,e,now*2+1,l,mid);
	else if(mid<s)return getval(s,e,now*2+2,mid+1,r);
	else return gcd(getval(s,e,now*2+1,l,mid),getval(s,e,now*2+2,mid+1,r));
}
int main(){
	io
	cin>>n>>q;
	segtree = vector<ll>(n*4,0LL);
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
	while(q--){
		char c;
		cin>>c;
		if(c == 'm'){
			ll p,v;
			cin>>p>>v;
			maketree(p-1,v,0,0,n-1);
		}
		else{
			ll s,e;
			cin>>s>>e;
			s--,e--;
			cout<<getval(s,e,0,0,n-1)<<'\n';
		}
	}
	
}

