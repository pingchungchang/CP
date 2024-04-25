#include <bits/stdc++.h>
using namespace std;


const int mxn = 1e5+10;
struct LCT{
    int rev[mxn],childs[mxn][2],par[mxn],val[mxn],sum[mxn];
    set<pair<int,int>> edges;
    int buf[mxn];
    LCT(){
        memset(rev,0,sizeof(rev));memset(childs,0,sizeof(childs));memset(par,0,sizeof(par));memset(val,0,sizeof(val));memset(sum,0,sizeof(sum));
    }
    void push(int now){
        if(!now)return;
        if(rev[now]){
            swap(childs[now][0],childs[now][1]);
            for(auto &i:childs[now]){
                if(i)rev[i]^=1;
            }
        }
        return;
    }
    void pull(int now){
        sum[now] = sum[childs[now][0]]^sum[childs[now][1]]^val[now];
        return;
    }
    int get(int now){
        if(!now)return 0;
        return childs[par[now]][1] == now;
    }
    void rotate(int now){
        int p = par[now],g = par[par[now]];
        push(g);push(p);push(now);
        if(g&&childs[g][get(p)] == p)childs[g][get(p)] = now;
        par[now] = g;
        int d = get(now);
        par[childs[now][d^1]] = p;
        childs[p][d] = childs[now][d^1];
        childs[now][d^1] = p;
        par[p] = now;
        pull(now);pull(p);pull(g);
        return;
    }
    void splay(int now){
        int tmp = now;
        int p = 0;
        while(childs[par[tmp]][get(tmp)] == tmp){
            buf[p++] = tmp;
            tmp = par[tmp];
        }
        p--;
        push(tmp);
        for(;p>=0;p--)push(buf[p]);
        while(childs[par[now]][get(now)] == now&&childs[par[par[now]]][get(par[now])] == par[now]){
            if(get(now) == get(par[now]))rotate(par[now]);
            else rotate(now);
            rotate(now);
        }
        if(childs[par[now]][get(now)] == now)rotate(now);
        return;
    }
    void access(int now){
        splay(now);
        childs[now][1] = 0;
        pull(now);
        while(par[now]){
            splay(now);
            push(par[now]);
            if(par[now])childs[par[now]][1] = now;
            now = par[now];
            pull(now);
        }
    }
    void makeroot(int now){
        rev[now]^=1;
        return;
    }
    int findroot(int now){
    }
    void link(int a,int b){
        if(findroot(a) == findroot(b))return;
        edges.insert({min(a,b),max(a,b)});
        makeroot(a);
        makeroot(b);
        par[b] = a;
    }
    void cut(int a,int b){
        if(findroot(a) != findroot(b))return;
        if(a>b)swap(a,b);
        if(edges.find({a,b}) == edges.end())return;
        edges.erase({a,b});
        makeroot(a);
        access(b);
        splay(b);
        par[childs[b][0]] = 0;
        childs[b][0] = 0;
        pull(b);
        return;
    }
    void dfs(int now){
        if(!now)return;
        // cout<<now<<' '<<childs[now][0]<<' '<<childs[now][1]<<' ';cout<<',';
        dfs(childs[now][0]);
        dfs(childs[now][1]);
    }
};

LCT lct = LCT();
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>lct.val[i];
        lct.sum[i] = lct.val[i];
    }
    while(m--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t == 0){
            lct.makeroot(x);
            lct.access(y);
            // lct.splay(x);
            // lct.dfs(x);
            cout<<lct.sum[x]<<'\n';
        }
        else if(t == 1){
            lct.link(x,y);
        }
        else if(t == 2){
            lct.cut(x,y);
        }
        else{
            lct.access(x);
            lct.sum[x] = lct.sum[x]^lct.val[x]^y;
            lct.val[x] = y;
        }
    }
    return 0;
}
/*
5 14
114
514
19
19
810
1 1 2
0 1 2
2 1 2
1 1 2
1 2 3
2 1 3
1 1 3
1 4 5
1 2 5
0 3 5
0 3 4
3 5 233333
0 1 5
0 2 5
*/