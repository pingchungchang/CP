#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
    vector<ll>childs;
    ll par;
    ll val;
    ll l,r;
    node(){
        l = 0,r = 0;
        val = 0;
    }
};
vector<ll> arr;
vector<node>tree;
ll n,q;
vector<ll> bit;
ll cnt = 1;
void dfs(ll now){
    tree[now].l = cnt++;
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par)continue;
        tree[nxt].par = now;
        dfs(nxt);
    }
    tree[now].r = cnt++;
    return;
}
void modify(ll pos,ll val){
    for(;pos<=cnt;pos += pos&(-pos))bit[pos]+=val;
    return;
}
ll sum(ll l,ll r){
    ll ans = 0;
    l--;
    for(;r>0;r-= r&-r)ans += bit[r];
    for(;l>0;l-=l&-l)ans -= bit[l];
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q;
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
    dfs(1);
    bit = vector<ll>(cnt+1,0LL);
    for(int i = 1;i<=n;i++){
        modify(tree[i].l,tree[i].val);
    }
    for(ll i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            ll s,x;
            cin>>s>>x;
            modify(tree[s].l,-tree[s].val);
            tree[s].val = x;
            modify(tree[s].l,tree[s].val);
        }
        else{
            ll s;
            cin>>s;
            cout<<sum(tree[s].l,tree[s].r)<<'\n';
        }
    }
}
