#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second
const int mxn = 2e5+10;

ll link_top[mxn],par[mxn],sz[mxn],idx[mxn],bit[mxn],dep[mxn];
pll bs[mxn];
vector<pii> tree[mxn];
ll vals[mxn];
ll C = 0;

void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
    return;
}
ll getval(int s,int e){
    ll re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}
void dfs1(int now){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt.fs == par[now])continue;
        par[nxt.fs] = now;
        dep[nxt.fs] = dep[now]+1;
        dfs1(nxt.fs);
        if(!bs[now].fs||sz[bs[now].fs]<sz[nxt.fs])bs[now] = nxt;
        sz[now] += sz[nxt.fs];
    }
    return;
}

void dfs2(int now,int top,int val){
    link_top[now] = top;
    idx[now] = ++C;
    vals[now] = val;
    modify(idx[now],val);
    if(bs[now].fs)dfs2(bs[now].fs,top,bs[now].sc);
    for(auto nxt:tree[now]){
        if(nxt.fs == par[now]||nxt.fs == bs[now].fs)continue;
        dfs2(nxt.fs,nxt.fs,nxt.sc);
    }
    return;
}

ll lca(ll a,ll b){
    ll ta = link_top[a],tb = link_top[b];
    ll re = 0;
    while(ta != tb){
        if(dep[ta]<dep[tb])swap(ta,tb),swap(a,b);
        re += getval(idx[ta],idx[a]);
        a = par[ta];
        ta = link_top[a];
    }
    if(a == b)return re;
    return re + getval(min(idx[a],idx[b])+1,max(idx[a],idx[b]));
}

pll edges[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
        edges[i] = {a,b};
    }
    par[1] = 1;
    dep[1] = 1;
    // cout<<"HI"<<endl;return 0;
    dfs1(1);
    dfs2(1,1,0);
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int id,w;
            cin>>id>>w;
            if(dep[edges[id].fs]<dep[edges[id].sc])id = edges[id].sc;
            else id = edges[id].fs;
            modify(idx[id],w-vals[id]);
            vals[id] = w;
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<lca(a,b)<<'\n';
        }
    }
    return 0;
}