#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
struct node{
    int pri;
    node *pl,*pr;
    bool tag;
    int sz;
    char val;
    int id;
    node(){}
    node(char c){
        val = c;
        pl = pr = 0;
        pri = rand();
        sz = 1;
        id = 0;
        tag = false;
    }
};
int sz(node* p){
    if(!p)return 0;
    else return p->sz;
}
node* treap = 0;
void push(node* now){
    if(!now->tag)return;
    if(now->pl)now->pl->tag ^=1;
    if(now->pr)now->pr->tag ^=1;
    swap(now->pl,now->pr);
    now->tag = 0;
    now->sz = sz(now->pl)+sz(now->pr)+1;
    return;
}
node* combine(node*a,node* b){
    if(!a)return b;
    if(!b)return a;
    push(a);
    push(b);
    if(a->pri<b->pri){
        b->pl = combine(a,b->pl);
        b->sz = (b->pl?b->pl->sz:0)+(b->pr?	b->pr->sz:0)+1;
        return b;
    }
    else{
        a->pr = combine(a->pr,b);
        a->sz = (a->pl?a->pl->sz:0)+(a->pr?a->pr->sz:0)+1;
        return a;
    }
}
void split(node* now,int p,node* &a,node* &b){
    if(!now){
        a = b = 0;
        return;
    }
//    cout<<now->id<<' '<<now->sz-sz(now->pr)<<' '<<p<<endl;
    push(now);
    if(now->sz-sz(now->pr)<p){
        a = now;
        split(now->pr,p-sz(now)+sz(now->pr),a->pr,b);
    }
    else if(now->sz-sz(now->pr) == p){
    	a = now;
    	b = now->pr;
    	a->pr = 0;
	}
    else{
        b = now;
        split(now->pl,p,a,b->pl);
    }
    if(a)a->sz = sz(a->pl)+sz(a->pr)+1;
    if(b)b->sz = sz(b->pl)+sz(b->pr)+1;
    return;
}
void pv(node* now){
    if(!now)return;
    push(now);
    pv(now->pl);
    cout<<now->val;
    pv(now->pr);
    return;
}
void pv2(node* now){
	if(!now)return;
	cout<<now->id<<' '<<sz(now)<<' '<<(now->pl?now->pl->id:0)<<' '<<(now->pr?now->pr->id:0)<<endl;
	pv2(now->pl);
	pv2(now->pr);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        char c;
        cin>>c;
        node* tmp = new node(c);
        tmp->id = i;
        treap = combine(treap,tmp);
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        node *a,*b,*c,*d;
        split(treap,e,a,b);
        split(a,s-1,c,d);
//        pv(d);cout<<',';
        d->tag ^=1;
        a = combine(c,d);
        treap = combine(a,b);
//        pv(treap);cout<<endl;
    }
    pv(treap);
}
