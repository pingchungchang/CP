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
	node *pl,*pr;
	ll l,r;
	ll val;
	node(){
		val = 0;
		pl = pr = 0;
	}
	node(ll s,ll e){
		l = s;r = e;
		pl = pr = 0;
		val = 0;
	}
};
void changeval(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val = v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)changeval(now->pl,p,v);
	else changeval(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
	return;
}
ll getval(node* now,ll s,ll e){
	if(now == 0)return 0;
	if(s<=now->l&&e>=now->r)return now->val;
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else return getval(now->pl,s,e)+getval(now->pr,s,e);
}
int main(){
	io
	ll n,q;
	node* segtree = new node(0,n-1);
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		changeval(segtree,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll p,v;
			cin>>p>>v;
			changeval(segtree,p,v);
		}
		else{
			ll s,e;
			cin>>s>>e;
			cout<<getval(segtree,s,e-1)<<'\n';
		}
	}
}

