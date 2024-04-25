#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double



const ll mod = 998244353;
ll pw(ll a,ll b){
	ll re = 1LL;
	while(b != 0){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
struct node{
	ll atag,rtag;
	ll val;
	node(){
		atag = rtag = 0LL;
		val = 0LL;
	}
};
vector<node> segtree;

void addval(ll now,ll l,ll r,ll s,ll e,ll a,ll d){
	if(l>=s&&e>=r){
		
	}
}
int main(){
	io
	ll n,x;
	cin>>n>>x;
	segtree = vector<node>(n*4+4,node());
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		addval(0,1,n,i,i,k,k);
	}
	ll q;
	cin>>q;
	while(q--){
		ll t;
		cin>>t;
		if(t == 1){
			ll s,e;
			cin>>s>>e;
			addval(0,1,n,s,e,x,x);
		}
		else{
			ll s,e;
			cin>>s>>e;
			cout<<getval(0,1,n,s,e)<<"\n";
		}
	}
}

