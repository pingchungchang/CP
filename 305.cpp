#include <bits/stdc++.h>
using namespace std;

const int mxn = 4e5+10;
#define ll long long
#define int ll
struct node{
    int key,ktag;
    int pl,pr,pri,tag,val,sum;
    int sz;
    node(){}
};
node treap[mxn];
#define pool treap
int ppp = 0;
int newnode(){
    ppp++;
    treap[ppp].sz = 1;
    pool[ppp].ktag = 
    pool[ppp].key = 
    pool[ppp].pl = 
    pool[ppp].pr = 
    pool[ppp].tag = 
    pool[ppp].val = 
    pool[ppp].sum = 0;
    pool[ppp].pri = rand()*rand()+rand();
    return ppp;
}
void push(int now){
    treap[now].val += treap[now].tag;
    treap[now].key += treap[now].ktag;
    if(treap[now].pl){
        treap[treap[now].pl].tag += treap[now].tag;
        treap[treap[now].pl].ktag += treap[now].ktag;
    }
    if(treap[now].pr){
        treap[treap[now].pr].tag += treap[now].tag;
        treap[treap[now].pr].ktag += treap[now].ktag;
    }
    treap[now].sum += treap[now].sz*treap[now].tag;
    treap[now].ktag = 0;
    treap[now].tag = 0;
}
void pull(int now){
    treap[now].sum = treap[now].val;
    treap[now].sz = 1;
    if(treap[now].pl){
        int lef = treap[now].pl;
        treap[now].sz += treap[lef].sz;
        treap[now].sum += treap[lef].sum+treap[lef].tag*treap[lef].sz;
    }
    if(treap[now].pr){
        int lef = treap[now].pr;
        treap[now].sz += treap[lef].sz;
        treap[now].sum += treap[lef].sum+treap[lef].tag*treap[lef].sz;
    }
    return;
}
int merge(int a,int b){
    if(!a)return b;
    if(!b)return a;
    if(treap[a].pri>treap[b].pri){
        push(a);
        treap[a].pr = merge(treap[a].pr,b);
        pull(a);
        return a;
    }
    else{
        push(b);
        treap[b].pl = merge(a,treap[b].pl);
        pull(b);
        return b;
    }
}
void split(int now,int &a,int &b){
    if(!now){
        a = b = 0;
        return;
    }
    push(now);
    if(treap[now].key<=0){
        a = now;
        split(treap[now].pr,treap[a].pr,b);
        pull(a);
    }
    else{
        b = now;
        split(treap[now].pl,a,treap[b].pl);
        pull(b);
    }
}
void pv(int now){
    if(!now)return;
    pv(treap[now].pl);
    cout<<treap[now].key<<' '<<treap[now].ktag<<' '<<treap[now].val<<' '<<treap[now].tag<<' '<<treap[now].sz<<endl;
    pv(treap[now].pr);
}
main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long ans =0;
    int now = newnode();
    // for(int i = 0;i<n;i++){
    //     auto tmp = newnode();
    //     treap[tmp].key = i*pow(-1,i);
    //     now = merge(now,tmp);
    // }
    // pv(now);return 0;
    if(s[0] == '('){
        treap[now].key = 1;
    }
    for(int i = 1;i<n;i++){
        if(s[i] == '('){
            auto tmp = newnode();
            now = merge(newnode(),now);
            treap[now].ktag++;
        }
        else{
            int l,r;
            split(now,l,r);
            treap[r].ktag--;
            treap[r].tag += 2;
            // cout<<")";
            // pv(r);cout<<endl;
            now = merge(l,r);
            now = merge(newnode(),now);
        }
        // cout<<treap[now].sum+treap[now].tag*treap[now].sz<<endl;
        // pv(now);cout<<endl;
        ans += treap[now].sum+treap[now].tag*treap[now].sz;
    }
    cout<<ans;
}