#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
struct splay_tree{
    int childs[mxn][2];
    int par[mxn];
    int sz[mxn];
    int rev[mxn];
    int val[mxn];
    int ptr;
    splay_tree(){
        memset(childs,0,sizeof(childs));
        memset(par,0,sizeof(par));
        memset(sz,0,sizeof(sz));
        ptr = 0;
        memset(rev,0,sizeof(rev));
        memset(val,0,sizeof(val));
    }
    int new_node(int k){
        ptr++;
        val[ptr] = k;
        sz[ptr] = 1;
        return ptr;
    }
    void push(int id){
        if(!id)return;
        int ls = childs[id][0],rs = childs[id][1];
        if(rev[id]){
            swap(childs[id][0],childs[id][1]);
            rev[ls]^= 1;
            rev[rs]^= 1;
        }
        rev[id] = 0;
        return;
    }
    void pull(int id){
        if(!id)return;
        int ls = childs[id][0],rs = childs[id][1];
        sz[id] = sz[ls]+sz[rs]+1;
        return;
    }
    bool get(int id){
        if(!id||!par[id])return 0;
        if(childs[par[id]][0] == id)return 0;
        else if(childs[par[id]][1] == id)return 1;
        else{
            cout<<"ERROR "<<id<<endl;
            return 0;
        }
    }
    void rotate(int id){
        push(par[id]);
        push(id);
        int lr = get(id);
        int p = par[id];
        int g = par[par[id]];
        childs[g][get(p)] = id;
        par[id] = g;
        childs[p][lr] = childs[id][lr^1];
        par[childs[id][lr^1]] = p;
        childs[id][lr^1] = p;
        par[p] = id;
        pull(p);
        pull(id);
        pull(g);
        return;
    }
    void splay(int id){
        if(!id)return;
        while(par[id]){
            if(par[par[id]])push(par[par[id]]);
            push(par[id]);
            push(id);
            if(!par[par[id]]){
                rotate(id);
                return;
            }
            if(get(par[id]) == get(id))rotate(par[id]);
            else rotate(id);
            rotate(id);
        }
    }
    void pv(int id){
        if(!id)return;
        cout<<id<<' '<<childs[id][0]<<' '<<childs[id][1]<<',';
        pv(childs[id][0]);
        pv(childs[id][1]);
    }
    void merge(int a,int b){
         if(!a||!b)return;
         splay(a);
         splay(b);
         push(a);
         push(b);
         while(childs[a][1]){
            a = childs[a][1];
            push(a);
         }
         while(childs[b][0]){
            b = childs[b][0];
            push(b);
         }
         splay(a);
         push(a);
         splay(b);
         childs[a][1] = b;
         par[b] = a;
         pull(a);
         return;
    }
    void dfs(int now = 1){
        if(!now)return;
        push(now);
        dfs(childs[now][0]);
        cout<<val[now]<<' ';
        dfs(childs[now][1]);
        return;
    }
    int find(int head,int k){
        if(!k)return 0;
        splay(head);
        while(head&&k){
            push(head);
            int ls = childs[head][0],rs = childs[head][1];
            if(sz[ls]+1 == k){
                splay(head);
                return head;
            }
            else if(sz[ls]+1<k){
                k -= sz[ls]+1;
                head = rs;
            }
            else head = ls;
        }
        splay(head);
        return head;
    }
    pair<int,int> split(int head,int k){
        if(k == 0){
            splay(head);
            return make_pair(0,head);
        }
        head = find(head,k);
        splay(head);
        int tmp = childs[head][1];
        childs[head][1] = par[tmp] = 0;
        pull(tmp);
        pull(head);
        return make_pair(head,tmp);
    }
};

splay_tree tree = splay_tree();

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        auto k = tree.new_node(i);
        if(i != 1)tree.merge(1,k);
        while(tree.par[k])k = tree.par[k];
    }
    while(m--){
        string s;
        cin>>s;
        if(s == "REV"){
            int l,r;
            cin>>l>>r;
            auto a = tree.split(1,r);
            tree.splay(a.first);
            auto b = tree.split(a.first,l-1);
            tree.splay(b.second);
            tree.rev[b.second] ^= 1;
            tree.merge(b.first,b.second);
            tree.merge(a.first,a.second);
            tree.splay(1);
        }
        else{
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            tree.splay(r1);
            auto ta = tree.find(1,l1-1);
            auto tb = tree.find(1,r1),tc = tree.find(1,l2-1),td = tree.find(1,r2),te = tree.find(1,n);
            tree.split(1,r2);
            tree.split(tc,l2-1);
            tree.split(tb,r1);
            tree.split(ta,l1-1);
            tree.merge(ta,td);
            tree.merge(td,tc);
            tree.merge(td,tb);
            if(td != te)tree.merge(td,te);
        }
    }
    tree.splay(1);
    tree.dfs(1);
    return 0;
}

/*
7 2
REV 1 4
SWAP 1 2 5 7

*/