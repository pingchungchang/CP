#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    ll par;
    ll big_son;
    ll val;
    ll idx;
    ll sz;
    ll dep;
    vector<ll>childs;
    ll link_top;
    node(){
        dep = 0LL;
        sz = 1LL;
        big_son = -1;
        link_top = -1;
        val = 0;
        idx = -1;
    }
};
vector<node> tree;
vector<ll> fenwick;
ll n,q;
ll cnt = 1;
void dfs1(ll now){
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par)continue;
        tree[nxt].par = now;
        tree[nxt].dep = tree[now].dep+1;
        dfs1(nxt);
        tree[now].sz+= tree[nxt].sz;
        if(tree[now].big_son == -1||tree[tree[now].big_son].sz<tree[nxt].sz){
            tree[now].big_son = nxt;
        }
    }
    return;
}
void dfs2(ll now,ll top){
    tree[now].idx = cnt++;
    tree[now].link_top = top;
    if(tree[now].big_son != -1)dfs2(tree[now].big_son,top);
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par||nxt == tree[now].big_son)continue;
        dfs2(nxt,nxt);
    }
    return;
}
void modify(ll pos,ll val){
    for(;pos<=n;pos += pos&-pos)fenwick[pos] += val;
    return;
}
ll getsum(ll s,ll e){
    s--;
    ll ans =0;
    for(;e>0;e-= e&-e)ans += fenwick[e];
    for(;s>0;s-= s&-s)ans -= fenwick[s];
    return ans;
}
ll getans(ll a,ll b){
    if(tree[a].dep<tree[b].dep)swap(a,b);
    ll ta = tree[a].link_top,tb = tree[b].link_top;
    ll ans = 0;
    while(ta != tb){
        ans += getsum(tree[ta].idx,tree[a].idx);
        if(tree[a].dep<tree[b].dep){
            swap(a,b);
            swap(ta,tb);
        }
        a = tree[ta].par;
        ta = tree[tree[ta].par].link_top;
    }
    if(tree[a].dep>tree[b].dep)swap(a,b);
    ans += getsum(tree[a].idx,tree[b].idx);
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    tree = vector<node>(n+1,node());
    for(ll i = 1;i<=n;i++){
        cin>>tree[i].val;
    }
    for(ll i = 0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        tree[a].childs.push_back(b);
        tree[b].childs.push_back(a);
    }
    tree[1].dep = 0;
    dfs1(1);
    dfs2(1,1);
    fenwick = vector<ll>(cnt,0LL);
    for(ll i = 1;i<=n;i++){
        modify(tree[i].idx,tree[i].val);
    }
    for(ll i = 0;i<q;i++){
        ll t;
        cin>>t;
        if(t ==1){
            ll s,x;
            cin>>s>>x;
            modify(tree[s].idx,-tree[s].val);
            tree[s].val = x;
            modify(tree[s].idx,x);
        }
        else{
            ll s;
            cin>>s;
            cout<<getans(1,s)<<'\n';
        }
    }
}
