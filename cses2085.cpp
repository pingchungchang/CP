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

const ll inf = 1e18;
struct line{
	ll m,b;
	line(){
		m = 0,b = inf;
	}
	line(ll mm,ll bb){
		m = mm,b = bb;
	}
	ll operator()(ll k){
		return m*k+b;
	}
};
struct node{
	ll l,r;
	line val;
	node *pl,*pr;
	node(){
		pl = pr = 0;
	}
	node(ll lll,ll rrr){
		l = lll,r = rrr;
		pl = pr =0;
		val = line(0,inf);
	}
};
void push(node* now){
	if(now->l == now->r)return;
	ll mid = now->l+(now->r-now->l)/2;
	now->pl = new node(now->l,mid);
	now->pr = new node(mid+1,now->r);
	return;
}
void addline(node* now,line x){
	if(now->l == now->r){
		if(now->val(now->l)>x(now->l)){
			now->val = x;
		}
		return;
	}
	ll mid = now->l+(now->r-now->l)/2;
	if(now->val(mid)>x(mid)){
		line c = now->val;
		now->val = x;
		x = c;
	}
//	cout<<now->l<<' '<<now->r<<' '<<now->val.m<<' '<<now->val.b<<' '<<x.m<<' '<<x.b<<' '<<now->val(mid)<<' '<<x(mid)<<endl;
	if(now->val.m == x.m){
		return;
	}
	if(!now->pl)push(now);
	if(now->val.m>x.m){
		addline(now->pr,x);
	}
	else{
		addline(now->pl,x);
	}
	return;
}
ll getval(node* now,ll p){
//	if(p == 30){
//		cout<<now->l<<' '<<now->r<<' '<<now->val(p)<<endl;
//	}
	if(!now->pl)return now->val(p);
	ll mid = now->l+(now->r-now->l)/2;
	if(mid>=p)return min(now->val(p),getval(now->pl,p));
	else return min(now->val(p),getval(now->pr,p));
}
void pv(node* now){
	if(!now)return;
	cout<<now->l<<' '<<now->r<<' '<<now->val.m<<' '<<now->val.b<<endl;
	pv(now->pl);
	pv(now->pr);
	return;
}
node* segtree = new node(0,INT_MAX);
int main(){
	io
	ll n,x;
	cin>>n>>x;
	pll req[n];
	for(auto &i:req)cin>>i.fs;
	for(auto &i:req)cin>>i.sc;
	addline(segtree,line(x,0));
	ll ans = 0;
	for(auto &i:req){
		ll s = i.fs,f = i.sc;
		ans = getval(segtree,s);
//		cout<<f<<' '<<ans<<endl;
		addline(segtree,line(f,ans));
//		pv(segtree);
//		cout<<endl;
	}
	cout<<ans;
}
/*
7 10
44 67 59 99 10 30 99 
14 84 77 3 13 76 3 
*/
