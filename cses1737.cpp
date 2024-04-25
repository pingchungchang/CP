#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    ll val;
    ll l,r;
    node* pr;
    node* pl;
    node(ll a,ll b,ll c){
        l = a,r = b,val = c;
        pr = nullptr;
        pl = nullptr;
    }
    node(){
        l = 0,r =0,val =0;
        pl = nullptr;
        pr = nullptr;
    }
};


vector<node*> trees;
vector<ll>inits;
ll n,q;
void init(node* now){
    //cout<<now->l<<' '<<now->r<<endl;
    if(now->l == now->r){
        //cout<<now->l<<endl;
        now->val = inits[now->r];
        return;
    }
    ll mid = (now->l+now->r)/2;
    now->pl = new node(now->l,mid,0);
    now->pr = new node(mid+1,now->r,0);
    init(now->pl);
    init(now->pr);
    now->val = now->pl->val+now->pr->val;
    return;
}
void changeval(node* now,ll pos,ll v){
    if(now->l == now->r){
        now->val =v;
        return;
    }
    if(now->pl == nullptr||now->pr == nullptr){
        cout<<now->l<<' '<<now->r<<"error\n";
        return;
    }
    ll mid = (now->l+now->r)/2;
    if(mid>=pos){
        //cout<<now->l<<' '<<now->r<<' '<<pos<<'l'<<endl;
        node* tmp = new node(now->l,mid,now->pl->val);
        tmp->pl = now->pl->pl;
        tmp->pr = now->pl->pr;
        now->pl = tmp;
        changeval(now->pl,pos,v);
    }
    else{
        node* tmp = new node(mid+1,now->r,now->pr->val);
        //cout<<now->l<<' '<<now->r<<' '<<pos<<'r'<<endl;
        tmp->pl = now->pr->pl;
        tmp->pr = now->pr->pr;
        now->pr = tmp;
        changeval(now->pr,pos,v);
    }
    now->val = now->pl->val+now->pr->val;
    return;
}
ll getval(node* now,ll s,ll e){
    if(s<=now->l&&e>=now->r)return now->val;
    ll mid = (now->l+now->r)/2;
    if(mid>=e)return getval(now->pl,s,e);
    else if(mid<s)return getval(now->pr,s,e);
    else return getval(now->pl,s,e)+getval(now->pr,s,e);
}
int main(){
    cin>>n>>q;
    trees.push_back(new node(0,n-1,0));
    inits = vector<ll>(n);
    for(ll i = 0;i<n;i++){
        cin>>inits[i];
    }
    init(trees[0]);
    for(ll i = 0;i<q;i++){
        ll t;
        cin>>t;
        if(t == 1){
            ll k,a,x;
            cin>>k>>a>>x;
            changeval(trees[k-1],a-1,x);
        }
        else if(t == 2){
            ll k,a,b;
            cin>>k>>a>>b;
            cout<<getval(trees[k-1],a-1,b-1)<<'\n';
        }
        else{
            ll k;
            cin>>k;
            trees.push_back(new node(0,n-1,trees[k-1]->val));
            trees.back()->pl = trees[k-1]->pl;
            trees.back()->pr = trees[k-1]->pr;
        }
    }
}
