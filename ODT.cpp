#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	ll l;
	ll r;
	mutable ll val;
	node(ll a,ll b,ll c){
		l = a;
		r = b;
		val = c;
	}
	node(){};
	bool operator<(const node& a)const{
		return l<a.l;
	}
};
bool cmp(const node &a,const node &b){
	return a.l<b.l;
}
list<node> odt;
void p(){
	for(auto i:odt){
		cout<<i.l<<','<<i.r<<','<<i.val<<';';
	}
	cout<<'\n';
}

list<node>::iterator split(ll pos){
	auto it = --upper_bound(odt.begin(),odt.end(),node(pos,0,0),cmp);
	if(it->l == pos)return it;
	ll l = it->l,r = it->r,v = it->val;
	odt.insert(it,node(l,pos-1,v));
	odt.insert(it,node(pos,r,v));
	auto it2 = --odt.erase(it);
	return it2;
}
void add(ll l,ll r,ll val){
	auto rit = split(r+1);
	auto lit = split(l);
	for(auto it = lit;it!=rit;it++){
		it->val += val;
	}
	return;
}
void assign(ll l,ll r,ll v){
	auto rit = split(r+1);
	auto lit = split(l);
	odt.erase(lit,rit);
	odt.insert(upper_bound(odt.begin(),odt.end(),node(l,0,0),cmp),node(l,r,v));
	return;
}
ll kth(ll l,ll r,ll v){
	auto rit = split(r+1);
	auto lit = split(l);
	ll total = 0;
	vector<pair<ll,ll>> vv;
	for(auto it = lit;it != rit;it++){
		vv.push_back(make_pair(it->val,it->r-it->l+1));
	}
	sort(vv.begin(),vv.end());
	for(auto i:vv){
		total += i.second;
		if(total>=v)return i.first;
	}
	return -1;
}
ll pw(ll n,ll t,ll mod){
	n%=mod;
	ll ans = 1;
	ll now = n;
	while(t != 0){
		if((t&1))ans *= now;
		now = (now*now)%mod;
		ans %= mod;
		t>>=1;
	}
	return ans;
}
ll psum(ll l,ll r,ll k,ll mod){
	auto rit = split(r+1);
	auto lit = split(l);
	ll ans = 0;
	for(auto it = lit;it != rit;it++){
		ans += (it->r-it->l+1)%mod*pw(it->val,k,mod)%mod;
		ans %= mod;
	}
//	cout<<'\n';
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	odt.push_back(node(0,0,-1));
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		odt.push_back(node(i,i,(ll)k));
	}
	odt.push_back(node(n+1,n+1,-1));
	for(ll i = 0;i<m;i++){
		ll t;
		cin>>t;
		ll l,r;
		ll v;
		cin>>l>>r>>v;
		if(t == 1){

			add(l,r,v);
		}
		else if(t == 2){
			assign(l,r,v);
		}
		else if(t == 3){
			cout<<kth(l,r,(ll)v)<<'\n';
		}
		else{
			ll mod;
			cin>>mod;
			cout<<psum(l,r,v,mod)<<'\n';
		}
//		p();
	}
}

/*
10 10
8 9 7 2 3 1 5 6 4 8
2 6 7 9
1 3 10 8
4 4 6 2 4
1 4 5 8
2 1 7 1
4 7 9 4 4
1 2 7 9
4 5 8 1 1
2 5 7 5
4 3 10 8 5

4 11
9 4 16 4 
2 2 4 169
4 1 1 141 18556
2 1 4 128
4 3 4 121 2383
2 1 1 189
3 1 3 0
4 4 4 240 12243
2 1 1 98
4 2 4 286 32238
2 2 3 107
2 4 4 6

*/
