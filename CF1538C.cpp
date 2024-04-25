#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	node* pl;
	node* pr;
	ll l,r,val;
	node(ll lll,ll rr){
		l = lll;
		r = rr;
		pl = pr = 0;
		val = 0;
	}
	node(){
		pl = pr = 0;
		val = 0;
	}
};
ll getval(node* now,ll s,ll e){
	if(now == 0)return 0;
	if(s<=now->l&&e>=now->r)return now->val;
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else return getval(now->pl,s,e)+getval(now->pr,s,e);
}
void changeval(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val += v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)changeval(now->pl,p,v);
	else changeval(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
	return;
}
node* segtree = new node(-1e9,1e9);
void solve(){
	ll n,l,r;
	cin>>n>>l>>r;
	ll ans = 0;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++){
		cin>>v[i];
		ans += getval(segtree,l-v[i],r-v[i]);
		changeval(segtree,v[i],1LL);
	}
	for(auto i:v){
		changeval(segtree,i,-1LL);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

