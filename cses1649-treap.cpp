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
	ll tag,pri,key,val;
	node(){
		pri = rand();
		tag = 0;
		key = 0;
		val = 0;
		l = r = 0;
	}
	node(ll p,ll k){
		l = r = 0;
		val = k;
		key = p;
		tag = k;
		pri = rand();
	}
};

node* merge(node* a,node* b){
	if(!a)return b;
	if(!b)return a;
//	cout<<(!a?0:a->key)<<' '<<(!b?0:b->key)<<endl;
//	if(a->key>b->key)swap(a,b);
	if(a->pri>b->pri){
		a->r = merge(a->r,b);
		if(b != nullptr){
			b->tag = b->val;
			if(b->l != nullptr)b->tag = min(b->tag,b->l->tag);
			if(b->r != nullptr)b->tag = min(b->tag,b->r->tag);
		}
		if(a != nullptr){
			a->tag = a->val;
			if(a->l != nullptr)a->tag = min(a->tag,a->l->tag);
			if(a->r != nullptr)a->tag = min(a->tag,a->r->tag);
		}
		return a;
	}
	else{
		b->l = merge(a,b->l);
		if(b != nullptr){
			b->tag = b->val;
			if(b->l != nullptr)b->tag = min(b->tag,b->l->tag);
			if(b->r != nullptr)b->tag = min(b->tag,b->r->tag);
		}
		if(a != nullptr){
			a->tag = a->val;
			if(a->l != nullptr)a->tag = min(a->tag,a->l->tag);
			if(a->r != nullptr)a->tag = min(a->tag,a->r->tag);
		}
		return b;
	}
}
void split(node* now,ll k,node* &a,node* &b){
	if(!now){
		a = b = 0;
		return;
	}
	if(now->key>k){
		b = now;
		split(now->l,k,a,b->l);
		if(!b->l){
		}
	}
	else{
		a = now;
		split(now->r,k,a->r,b);
	}
	if(b != nullptr){
		b->tag = b->val;
		if(b->l != nullptr)b->tag = min(b->tag,b->l->tag);
		if(b->r != nullptr)b->tag = min(b->tag,b->r->tag);
	}
	if(a != nullptr){
		a->tag = a->val;
		if(a->l != nullptr)a->tag = min(a->tag,a->l->tag);
		if(a->r != nullptr)a->tag = min(a->tag,a->r->tag);
	}
	return;
}
void pv(node* now){
	if(!now)return;
	cout<<now->key<<' '<<(!now->l?0:now->l->key)<<' '<<(!now->r?0:now->r->key)<<'\n';
	pv(now->l);
	pv(now->r);
}
node* treap;
int main(){
	srand(time(NULL));
	io
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		ll kk;
		cin>>kk;
		node* tmp = new node(i,kk);
//		cout<<tmp->val<<' '<<tmp->pri<<' '<<tmp->key<<endl;
		treap = merge(treap,tmp);
//		cout<<i<<';';pv(treap);
	}
//	pv(treap);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll p,v;
			cin>>p>>v;
			node* a;node* b;node* pos;node* tmp;
			split(treap,p,a,b);
			split(a,p-1,tmp,pos);
			pos->val = pos->tag = v;
			treap = merge(tmp,pos);
			treap = merge(treap,b);
		}
		else{
			ll s,e;
			cin>>s>>e;
			node* a;node*b;node* c;node* d;
			split(treap,s-1,a,b);
			split(b,e,c,d);
			cout<<c->tag<<'\n';
//			pv(a);cout<<'\n';pv(b);cout<<'\n';pv(c);cout<<'\n';
			treap = merge(c,d);
			treap = merge(a,treap);
//			pv(treap);
		}
	}
	return 0;
}

