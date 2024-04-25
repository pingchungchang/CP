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
	node* l;
	node* r;
	ll val,tag,key,pri,total,sz;
	node(){
		val = tag = key = 0;
		pri = rand();
		total = 0;
		l = r = 0;
		sz = 1;
	}
	node(ll p,ll v){
		val = total = v;
		key = p;
		sz = 1;
		pri = rand();
		l = r= 0;
	}
};
void push(node* a){
	if(!a)return;
	if(a->l){
		a->l->tag += a->tag;
	}
	if(a->r)a->r->tag += a->tag;
	a->val+= a->tag;
	a->total += a->tag*a->sz;
	a->tag = 0;
	return;
}
void pv(node* now){
	if(!now)return;
	cout<<now->key<<' '<<(now->l?now->l->key:0)<<" "<<(now->r?now->r->key:0)<<'\n';
	pv(now->l);pv(now->r);
}
node* merge(node* a,node* b){
	if(!a)return b;
	if(!b)return a;
	node* returns;
	push(a);
	push(b);
	if(a->pri>b->pri){
		a->r = merge(a->r,b);
		returns = a;
	}
	else{
		b->l = merge(a,b->l);
		returns = b;
	}
	a->sz = 1+(a->l?a->l->sz:0)+(a->r?a->r->sz:0);
	b->sz = 1+(b->l?b->l->sz:0)+(b->r?b->r->sz:0);
	a->total = a->val+(a->l?a->l->total:0LL)+(a->r?a->r->total:0LL)+a->tag*a->sz;
	b->total = b->val+(b->l?b->l->total:0LL)+(b->r?b->r->total:0LL)+b->tag*b->sz;
	return returns;
}
void split(node* now,ll k,node* &a,node* &b){
	if(!now){
		a = b = 0;
		return;
	}
	push(now);
	if(now->key<=k){
		a = now;
		split(now->r,k,a->r,b);
	}
	else{
		b = now;
		split(now->l,k,a,b->l);
	}
//	if(a->l != nullptr)cout<<"pp\n";//<<a->l->sz<<endl;
//	else cout<<"p\n";
//	pv(a);cout<<endl;
//	cout<<now->key<<endl;
	if(a)a->sz = 1LL+(a->l?a->l->sz:0LL)+(a->r?a->r->sz:0LL);
	if(b)b->sz = 1LL+(b->l?b->l->sz:0)+(b->r?b->r->sz:0);
	if(a)a->total = a->val+(a->l?a->l->total:0)+(a->r?a->r->total:0)+a->tag*a->sz;
	if(b)b->total = b->val+(b->l?b->l->total:0)+(b->r?b->r->total:0)+b->tag*b->sz;	
	return;
}
node* treap;
int main(){
	io
	ll n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int kk;
		cin>>kk;
		treap = merge(treap,new node(i,kk));
	}
//	pv(treap);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			node* a;node* b;node* c;node* d;
			split(treap,s-1,a,b);
			split(b,e,c,d);
			c->tag += v;
			treap = merge(c,d);
			treap = merge(a,treap);
		}
		else{
			int p;
			cin>>p;
			node* a;node* b;node* c;node* d;
			split(treap,p,a,b);
//			pv(a);cout<<'\n';pv(b);cout<<'\n';
			split(a,p-1,c,d);
			cout<<d->val<<'\n';
//			pv(c);cout<<endl;
			treap = merge(c,d);
			treap = merge(treap,b);
		}
	}
	return 0;
	
}

