#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	node* pl;
	node* pr;
	pll val;
	ll l;
	ll r;
	node(ll lll,ll rrr){
		l = lll;
		r = rrr;
		pl = 0,pr = 0;
		val = make_pair(0,0);
	}
	node(){
		pr = 0;
		pl = 0;
		val = make_pair(0,0);
	}
};
node* segtree = new node(0,(ll)1e9+10);

void changeval(ll p,ll v,node* now){
	if(now->l == now->r){
		now->val.sc += v;
		now->val.fs ++;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pr == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)changeval(p,v,now->pl);
	else changeval(p,v,now->pr);
	now->val = make_pair(now->pl->val.fs+now->pr->val.fs,now->pr->val.sc+now->pl->val.sc);
}
pll getval(ll s,ll e,node* now){
	if(now == 0)return make_pair(0,0);
	if(now->l>=s&&now->r<=e){
		return now->val;
	}
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(s,e,now->pl);
	else if(mid<s)return getval(s,e,now->pr);
	else{
		pll a = getval(s,e,now->pl);
		pll b = getval(s,e,now->pr);
		return make_pair(a.fs+b.fs,a.sc+b.sc);
	}
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		changeval(k,k,segtree);
	}
//	cout<<getval(0,(ll)1e9+10,segtree).fs<<' '<<getval(0,(ll)1e9+10,segtree).sc<<endl;
	for(ll i = 0;i<q;i++){
		ll k;
		cin>>k;
		pll lef = getval(0,k,segtree);
		pll rig = getval(k+1,(ll)(1e9+10),segtree);
		cout<<k*lef.fs-lef.sc+rig.sc-k*rig.fs<<'\n';
	}
}

