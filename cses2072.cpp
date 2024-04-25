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
#pragma GCC optimize("Ofast")
struct node{
	node* pl,*pr;
	int pos;
	char val;
	int tag;
	int pri;
	node(int p,char c){
		pri = rand();
		val = c;
		pos = p;
		pl = pr = 0;
		tag = 0;
	}
	node(){
		tag = 0;
		pl = pr = 0;
		pri = rand();
	}
};
void push(node* now){
	now->pos += now->tag;
	if(now->pl)now->pl->tag += now->tag;
	if(now->pr)now->pr->tag += now->tag;
	now->tag = 0;
	return;
}
node* merge(node* a,node* b){
	if(!a)return b;
	if(!b)return a;
	push(a);
	push(b);
	if(a->pri<b->pri)swap(a,b);
	if(a->pos<b->pos)a->pr = merge(a->pr,b);
	else a->pl = merge(a->pl,b);
	return a;
}
void split(node* now,int p,node* &a,node* &b){
	if(!now){
		a = b = 0;
		return;
	}
	push(now);
	if(now->pos<p){
		a = now;
		split(now->pr,p,a->pr,b);
	}
	else{
		b = now;
		split(now->pl,p,a,b->pl);
	}
	
}
void pv(node* now){
	if(!now)return;
	push(now);
	pv(now->pl);
	cout<<now->val;
//	cout<<now->pos<<' '<<now->val<<',';
	pv(now->pr);
	return;
}
//a<p<=b
node* treap = 0;
main(){
	io
	srand(time(NULL));
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		char c;
		cin>>c;
		node* tmp = new node(i,c);
		treap = merge(treap,tmp);
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		node* a,*b,*c,*d;
		split(treap,l,a,b);
		split(b,r+1,c,d);
		if(!c)push(c);
		c->tag +=n-(r);
		if(d)d->tag -= (r-l+1);
//		cout<<d->pos+d->tag<<d->val<<endl;
		b = merge(c,d);
		treap = merge(a,b);
//		pv(treap);
//		return 0;
//		cout<<endl;
	}
	pv(treap);
}

