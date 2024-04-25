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

struct node{
	ll a,d,l,r,val;
	ll lval,rval;
	pll bigval;
	node *pl,*pr;
	node(){
		a = d = l = r = val = 0;
		pl = pr = 0;
		lval = rval = 0;
		bigval = {0,0};
	}
	node(ll lll,ll rrr){
		a = d = 0;
		val = 0LL;
		l = lll,r = rrr;
		pl = pr = 0;
		lval = rval = 0;
		bigval = make_pair(0,lll);
	}
};

void modify(node* now,ll s,ll e,ll x,ll dx){
	if(now->l>=s&&now->r<=e){
		now->a += x;
		now->d += dx;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->pl,mid);
		now->pr = new node(mid+1,now->pr);
	}
	push(now);
	if(mid>=s)modify(now->pl,s,e,x,dx);
	if(mid<e)modify(now->pr,s,e,(x+dx*(mid-now->pl+1)),dx);
	now->lval = now->pl->lval+now->pl->a;
	now->rval = now->pr->rval+now->pr->a+(now->pr->r-now->pr->l)*now->pr->d;
	now->bigval = max({now->pl->bigval.fs+now->pl->d*(now->pl->bigval.sc-now->l),now->pl->bigval.sc}
	,{now->pr->bigval.fs+now->pr->d*(now->pr->bigval.sc-mid-1),now->pr->bigval.sc});
	now->bigval = max(now->bigval,{now->lval,l});
	now->bigval = max(now->bigval,{now->rval,r});
}
void solve(){
	node* segtree = new node(0,(ll)1e9);
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

