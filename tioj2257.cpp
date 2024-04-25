#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second
vector<int> tree[mxn];
ll bit[mxn];
ll id,dep[mxn],par[mxn],link_top[mxn],bs[mxn],sz[mxn],idx[mxn];
pll edges[mxn];
void modify(int p,int v){
    for(;p<mxn;p+= p&-p)bit[p] += v;
    return;
}
ll getval(int s,int e){
    int re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}
void dfs1(int now){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par[now])continue;
        par[nxt] = now;
        dep[nxt] = dep[now]+1;
        dfs1(nxt);
        if(bs[now] == 0||sz[bs[now]]<sz[nxt])bs[now] = nxt;
        sz[now] += sz[nxt];
    }
    return;
}
void dfs2(int now,int top){
    idx[now] = ++id;
    link_top[now] = top;
    modify(idx[now],1);
    if(bs[now])dfs2(bs[now],top);
    for(auto nxt:tree[now]){
        if(nxt == par[now]||nxt == bs[now])continue;
        dfs2(nxt,nxt);
    }
    return;
}

ll lca(ll a,ll b){
    ll ta = link_top[a],tb = link_top[b];
    ll re = 0;
    while(ta != tb){
        if(dep[ta]<dep[tb]){
            swap(a,b);
            swap(ta,tb);
        }
        re += getval(idx[ta],idx[a]);
        a = par[ta];
        ta = link_top[a];
    }
    // cout<<a<<' '<<ta<<endl;
    if(a == b)return re;
    if(dep[a]>dep[b])swap(a,b);
    return re+getval(idx[a]+1,idx[b]);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,s,t,w;
    cin>>n>>s>>t>>w;
    t += w;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edges[i+1] = {a,b};
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dep[s] = 1;
    dfs1(s);
    dfs2(s,s);
    // return 0;
    // for(int i = 1;i<=n;i++)cout<<lca(s,i)<<endl;return 0;
    // for(int i = 1;i<=n;i++)cout<<link_top[i]<<' ';return 0;
    while(t--){
        int q;
        cin>>q;
        if(q==2){
            int k;
            cin>>k;
            if(dep[edges[k].fs]>dep[edges[k].sc])swap(edges[k].fs,edges[k].sc);
            modify(idx[edges[k].sc],-1);
        }
        else{
            ll x,y;
            cin>>x>>y;
            cout<<1LL*x*lca(s,y)<<'\n';
        }
    }
    return 0;
}