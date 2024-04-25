#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	mutable ll val;
	ll l;
	ll r;
	node(ll a,ll b,ll c):l(a),r(b),val(c){}
	node(ll a):l(a){}
	bool operator<(const node & a)const{
		return l<a.l;
	}
};
set<node> ctholly;

set<node>::iterator split(ll pos){
	auto it = ctholly.lower_bound(node(pos));
	if(it != ctholly.end()&&it->l == pos)return it;
	--it;
	ll l = it->l,r = it->r,v = it->val;
	ctholly.erase(it);
	ctholly.insert(node(l,pos-1,v));
	return ctholly.insert(node(pos,r,v)).fs;
}

void assign(ll l,ll r,ll v){
	auto rit = split(r+1);
	auto lit = split(l);
	ctholly.erase(lit,rit);
	ctholly.insert(node(l,r,v));
	return;	
}
void add(ll l,ll r,ll v){
	auto rit = split(r+1);
	auto lit = split(l);
	for(auto it = lit;it != rit;it++){
		it->val += v;
	}
}
ll kth(ll l,ll r,ll k){
	auto rit = split(r+1);
	auto lit = split(l);
	vector<pll> v;
	for(auto it = lit;it != rit;it++){
		v.push_back(make_pair(it->val,it->r-it->l+1));
	}
	sort(v.begin(),v.end());
	ll total = 0;
	for(auto i:v){
		total += i.sc;
		if(total>=k)return i.fs;
	}
	return -1;
}
ll pw(ll n,ll t,ll mod){
	n%= mod;
	ll ans = 1;
	ll now = n;
	while(t != 0){
		if((t&1))ans = (ans*now)%mod;
		now = (now*now)%mod;
		t>>=1;
	}
	return ans;
}
ll psum(ll l,ll r,ll t,ll mod){
	auto rit = split(r+1);
	auto lit = split(l);
	ll ans = 0;
	for(auto it = lit;it != rit;it++){
		ans += (it->r-it->l+1)%mod*pw(it->val,t,mod)%mod;
		ans %= mod;
	}
	return ans;
	
}
int main(){
	io
	ll n,m;
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		ctholly.insert(node(i,i,k));
	}
	for(ll i = 0;i<m;i++){
		ll t,s,e,v;
		cin>>t>>s>>e>>v;
		if(t == 1)add(s,e,v);
		else if(t == 2)assign(s,e,v);
		else if(t == 3)cout<<kth(s,e,v)<<'\n';
		else{
			ll mod;
			cin>>mod;
			cout<<psum(s,e,v,mod)<<'\n';
		}
	}
}

