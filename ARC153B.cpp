#include <bits/stdc++.h>
using namespace std;

struct node{
    int pl,pr,rev,val,sz;
    int pri;
    node(){}
};
const int mxn = 5e5+10;

node treap[mxn];
int pp = 0;
int newnode(int v){
    pp++;
    treap[pp].pri = rand();
    treap[pp].pl = treap[pp].pr = treap[pp].rev = 0;
    treap[pp].sz = 1;
    treap[pp].val = v;
    return pp;
}
void push(int now){
    if(!now)return;
    if(treap[now].rev){
        treap[now].rev = 0;
        swap(treap[now].pl,treap[now].pr);
        treap[treap[now].pl].rev ^= 1;
        treap[treap[now].pr].rev ^= 1;
    }
    return;
}
void pull(int now){
    if(!now)return;
    treap[now].sz = 1+treap[treap[now].pl].sz+treap[treap[now].pr].sz;
    return;
}
int merge(int a,int b){
    if(!b)return a;
    if(!a)return b;
    if(treap[a].pri<treap[b].pri){
        push(b);
        treap[b].pl = merge(a,treap[b].pl);
        pull(b);
        return b;
    }
    else{
        push(a);
        treap[a].pr = merge(treap[a].pr,b);
        pull(a);
        return a;
    }
}
void split(int now,int &a,int &b,int tar){
    if(!now){
        a = b = 0;
        return;
    }
    push(now);
    if(treap[treap[now].pl].sz+1 <= tar){
        a = now;
        split(treap[now].pr,treap[a].pr,b,tar-treap[treap[now].pl].sz-1);
    }
    else{
        b = now;
        split(treap[now].pl,a,treap[b].pl,tar);
    }
    pull(a);
    pull(b);
    return;
}

vector<vector<char>> v;
int ht,wt;
void dfs2(int row,int now){
    if(!now)return;
    push(now);
    dfs2(row,treap[now].pl);
    cout<<v[row][treap[now].val];
    dfs2(row,treap[now].pr);
}
void dfs1(int now){
    if(!now)return;
    push(now);
    dfs1(treap[now].pl);
    dfs2(treap[now].val,wt);
    cout<<'\n';
    dfs1(treap[now].pr);
}
void pv(int now){
    if(!now)return;
    pv(treap[now].pl);
    cout<<treap[now].val<<' ';
    pv(treap[now].pr);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w;
    cin>>h>>w;
    v = vector<vector<char>>(h+1,vector<char>(w+1));
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++)cin>>v[i][j];
    }
    ht = newnode(1);
    for(int i = 2;i<=h;i++){
        int k = newnode(i);
        ht = merge(ht,k);
    }
    wt = newnode(1);
    for(int i = 2;i<=w;i++){
        int k = newnode(i);
        wt = merge(wt,k);
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int ta,tb;
        split(ht,ta,tb,a);
        treap[ta].rev ^= 1;
        treap[tb].rev ^=1;
        ht = merge(ta,tb);
        split(wt,ta,tb,b);
        treap[ta].rev ^= 1;
        treap[tb].rev ^= 1;
        wt = merge(ta,tb);
    }
    // pv(ht);cout<<endl;
    // pv(wt);cout<<endl;return 0;
    dfs1(ht);
}