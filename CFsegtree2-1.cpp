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
	ll val,pre,suf,sum;
	node(){
		pl = pr = 0;
		l = r = val = pre = suf = sum = 0;
	}
	node(ll s,ll e){
		pl = pr = 0;
		l = s,r = e;
		val = pre = suf = sum = 0;
	}
};

void modify(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val = max(0LL,v);
		now->sum= v;
		now->pre = max(0LL,v);
		now->suf = max(0LL,v);
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p){
		modify(now->pl,p,v);
	}
	else modify(now->pr,p,v);
	now->pre = max(now->pl->pre,now->pl->sum+now->pr->pre);
	now->suf = max(now->pr->suf,now->pr->sum+now->pl->suf);
	now->sum = now->pl->sum+now->pr->sum;
	now->val = now->pl->suf+now->pr->pre;
	now->val = max(now->val,now->pl->val);
	now->val = max(now->val,now->pr->val);
	return;
}

int main(){
	io
	int n,q;
	cin>>n>>q;
	node* segtree = new node(0,n-1);
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		modify(segtree,i,k);
	}
	cout<<segtree->val<<'\n';
	while(q--){
		ll p,v;
		cin>>p>>v;
		modify(segtree,p,v);
		cout<<segtree->val<<'\n';
	}
	
}

