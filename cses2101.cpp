#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int idx[mxn],dep[mxn],sz[mxn],par[mxn],link_top[mxn];
pii bs[mxn];
vector<pii> tree[mxn];
int cnt = 1;
int segtree[mxn*4],dsu[mxn];

int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    dsu[root(a)] = root(b);
    return;
}
void modify(int now,int l,int r,int p,int v){
    if(l == r){
        segtree[now] = v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=p)modify(now*2+1,l,mid,p,v);
    else modify(now*2+2,mid+1,r,p,v);
    segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
    return;
}
int getval(int now,int l,int r,int s,int e){
    if(l>=s&&e>=r)return segtree[now];
    int mid = (l+r)>>1;
    if(mid>=e)return getval(now*2+1,l,mid,s,e);
    else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
    else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
void dfs(int now){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt.fs == par[now])continue;
        dep[nxt.fs] = dep[now]+1;
        par[nxt.fs] = now;
        dfs(nxt.fs);
        sz[now] += sz[nxt.fs];
        if(bs[now].fs == 0||sz[bs[now].fs]<sz[nxt.fs])bs[now] = nxt;
    }
    return;
}
void dfs2(pii now,int top){
    link_top[now.fs] = top;
    idx[now.fs] = cnt++;
    modify(0,0,mxn,idx[now.fs],now.sc);
    if(bs[now.fs].fs != 0)dfs2(bs[now.fs],top);
    for(auto nxt:tree[now.fs]){
        if(nxt.fs == par[now.fs]||nxt.fs == bs[now.fs].fs)continue;
        dfs2(nxt,nxt.fs);
    }
    return;
}
int lca(int a,int b){
    int ta = link_top[a],tb = link_top[b];
    int re = 0;
    while(ta != tb){
        if(dep[ta]<dep[tb]){
            swap(ta,tb);
            swap(a,b);
        }
        re = max(re,getval(0,0,mxn,idx[ta],idx[a]));
        a = par[ta];
        ta = link_top[a];
    }
    if(dep[a]>dep[b])swap(a,b);
    if(a == b)return re;
    return max(re,getval(0,0,mxn,idx[a]+1,idx[b]));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;i++)dsu[i] = i;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(root(a) == root(b))continue;
        onion(a,b);
        tree[a].push_back({b,i});
        tree[b].push_back({a,i});
    }
    for(int i = 1;i<=n;i++){
        if(root(i) == i){
            dfs(i);
            dfs2({i,0},i);
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(root(a) != root(b)){
            cout<<"-1\n";
            continue;
        }
        cout<<lca(a,b)<<'\n';
    }
    return 0;
}