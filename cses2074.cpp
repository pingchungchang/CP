#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct node{
    node* pl,*pr;
    int sz,pri;
    ll val,total;
    bool rev;
    int id;
    node(){}
    node(ll k){
        id = 0;
        total = k;
        pri = rand();
        val = k;
        rev = false;
        sz = 1;
        pl = pr = 0;
    }
};

node* treap = 0;
int sz(node* p){
    return (p?p->sz:0);
}
ll total(node* p){
    return (p?p->total:0);
}
void push(node* p){
    if(!p->rev)return;
    if(p->pl)p->pl->rev ^=1;
    if(p->pr)p->pr->rev ^=1;
    p->rev = 0;
    swap(p->pl,p->pr);
    return;
}
void pull(node* p){
    if(!p)return;
    p->total = p->val+total(p->pr)+total(p->pl);
    p->sz = 1+sz(p->pl)+sz(p->pr);
    return;
}
node* Merge(node* a,node* b){
    if(!a)return b;
    if(!b)return a;
    push(a);
    push(b);
    if(a->pri>b->pri){
        a->pr = Merge(a->pr,b);
        pull(a);
        return a;
    }
    else{
        b->pl = Merge(a,b->pl);
        pull(b);
        return b;
    }
}
void split(node* now,int p,node* &a,node* &b){
    if(!now){
        a = b= 0;
        return;
    }
    push(now);
    if(sz(now)-sz(now->pr)<p){
        a = now;
        split(now->pr,p-sz(now)+sz(now->pr),a->pr,b);
    }
    else if(sz(now)-sz(now->pr) == p){
        a = now;
        b = now->pr;
        a->pr = 0;
    }
    else{
        b = now;
        split(now->pl,p,a,b->pl);
    }
    pull(a);
    pull(b);
    return;
}
void pv(node* now){
    if(!now)return;
    cout<<now->id<<','<<now->total<<';'<<(now->pl?now->pl->id:0)<<' '<<(now->pr?now->pr->id:0)<<'\n';
    pv(now->pl);pv(now->pr);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        ll k;
        cin>>k;
        node*tmp = new node(k);
        tmp->id = i;
        treap = Merge(treap,tmp);
    }
    //pv(treap);
    while(q--){
        int t,s,e;
        cin>>t>>s>>e;
        node* a,*b,*c,*d;
        split(treap,e,a,b);
        split(a,s-1,c,d);
        //pv(d);cout<<endl;
        if(t == 1){
            d->rev ^= 1;
        }
        else cout<<d->total<<'\n';
        a = Merge(c,d);
        treap = Merge(a,b);
        //pv(treap);cout<<endl;
    }
    return 0;
}
