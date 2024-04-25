#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
struct Splay{
    int childs[mxn][2];
    int par[mxn];
    int val[mxn],rtag[mxn],sz[mxn];
    Splay(){
        memset(childs,0,sizeof(childs));
        memset(par,0,sizeof(par));
        memset(val,0,sizeof(val));
        memset(rtag,0,sizeof(rtag));
        fill(sz,sz+mxn,1);
        sz[0] = 0;
    }
    void push(int now){
        if(!now)return;
        if(rtag[now])swap(childs[now][0],childs[now][1]);
        for(auto &i:childs[now]){
            if(i&&rtag[now])rtag[i] ^= 1;
        }
        rtag[now] = 0;
        return;
    }
    void pull(int now){
        if(!now)return;
        sz[now] = 1;
        for(auto &i:childs[now]){
            if(i)sz[now] += sz[i];
        }
        return;
    }
    int get(int now){
        push(par[now]);
        return childs[par[now]][1] == now;
    }
    void rotate(int now){
        push(par[now]);
        push(now);
        int p = par[now];
        int k = get(now);
        childs[par[p]][get(p)] = now;
        par[now] = par[p];
        par[childs[now][k^1]] = p;
        childs[p][k] = childs[now][k^1];
        childs[now][k^1] = p;
        par[p] = now;
        pull(p);
        pull(now);
        return;
    }
    void splay(int now){
        while(par[now]&&par[par[now]]){
            push(par[par[now]]);
            push(par[now]);
            if(get(now) == get(par[now]))rotate(par[now]);
            else rotate(now);
            rotate(now);
        }
        if(par[now]){
            push(now);
            rotate(now);
        }
        return;
    }
    int find(int now,int r){
        splay(now);
        while(now){
            push(now);
            if(sz[childs[now][0]]+1 == r){
                splay(now);
                return now;
            }
            else if(sz[childs[now][0]]+1 < r){
                r -= sz[childs[now][0]]+1;
                now = childs[now][1];
            }
            else now = childs[now][0];
        }
        return 0;
    }
    pair<int,int> split(int now,int r){
        if(!r||!now)return {0,0};
        splay(now);
        auto pos = find(now,r);
        splay(pos);
        int k = childs[pos][1];
        par[k] = 0;
        childs[pos][1] = 0;
        pull(pos);
        return {pos,k};
    }
    void merge(int a,int b){
        if(!a||!b)return;
        splay(a);
        splay(b);
        int ra = find(a,sz[a]);
        int lb = find(b,1);
        // assert(ra != 0&&lb != 0);
        par[lb] = ra;
        childs[ra][1] = lb;
        pull(ra);
        return;
    }
    void dfs(int now){
        if(!now)return;
        push(now);
        dfs(childs[now][0]);
        cout<<val[now]<<' ';
        dfs(childs[now][1]);
    }
};
Splay tree = Splay();
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        tree.val[i] = i;
        if(i != 1)tree.merge(1,i);
        // cout<<endl;
    }
    // tree.splay(3);
    // tree.dfs(3);return 0;
    // return 0;
    while(m--){
        string s;
        cin>>s;
        if(s == "REV"){
            int l,r;
            cin>>l>>r;
            if(l == 1&&r == n){
                tree.splay(1);
                tree.rtag[1]^= 1;
            }
            else if(l == 1){
                auto p = tree.split(1,r);
                tree.rtag[p.first]^=1;
                tree.merge(p.first,p.second);
            }
            else if(r == n){
                auto p = tree.split(1,l-1);
                tree.rtag[p.second] ^= 1;
                tree.merge(p.first,p.second);
            }
            else{
                auto p2 = tree.split(1,r);
                auto p = tree.split(p2.first,l-1);
                tree.rtag[p.second]^=1;
                tree.merge(p.first,p.second);
                tree.merge(p2.first,p2.second);
            }
        }
        else{
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            // assert(r1 != l2-1);
            if(r2== n&&l1 == 1){
                auto p1 = tree.split(1,l2-1);
                auto p2 = tree.split(p1.first,r1);
                tree.merge(p1.second,p2.second);
                tree.merge(p2.second,p2.first);
            }
            else if(l1 == 1){
                auto p1 = tree.split(1,r2);
                auto p2 = tree.split(p1.first,l2-1);
                // assert(tree.sz[p2.first]>=r1);
                auto p3 = tree.split(p2.first,r1);
                tree.merge(p2.second,p3.second);
                tree.merge(p3.second,p3.first);
                tree.merge(p3.second,p1.second);
            }
            else if(r2 == n){
                auto p1 = tree.split(1,l2-1);
                auto p2 = tree.split(p1.first,r1);
                // assert(tree.sz[p2.first]>=l1-1);
                auto p3 = tree.split(p2.first,l1-1);
                tree.merge(p3.first,p1.second);
                tree.merge(p1.second,p2.second);
                tree.merge(p1.second,p3.second);
            }
            else{
                auto p1 = tree.split(1,r2);
                auto p2 = tree.split(p1.first,l2-1);
                auto p3 = tree.split(p2.first,r1);
                auto p4 = tree.split(p3.first,l1-1);
                tree.merge(p4.first,p2.second);
                tree.merge(p4.first,p3.second);
                tree.merge(p4.first,p4.second);
                tree.merge(p4.first,p1.second);
            }
        }
    }
    tree.splay(1);
    tree.dfs(1);
}
