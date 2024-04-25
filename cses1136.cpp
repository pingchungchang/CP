#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
    ll par[32];
    vector<ll> childs;
    ll tag;
    ll depth;
    ll ans;
    node(){
        depth = 0;
        tag = 0;
        ans = 0;
        memset(par,0LL,sizeof(par));
    }
};
ll n,m;
node tree[200010];
void dfs(ll now){
    for(ll i = 1;i<32;i++){
        tree[now].par[i] = tree[tree[now].par[i-1]].par[i-1];
    }
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par[0])continue;
        tree[nxt].par[0] = now;
        tree[nxt].depth = tree[now].depth+1;
        dfs(nxt);
    }
    return;
}
ll lca(ll a,ll b){
    if(tree[a].depth>tree[b].depth)swap(a,b);
    ll dif = tree[b].depth-tree[a].depth;
    for(ll i = 0;i<32;i++){
        if((dif&(1LL<<i)) != 0)b = tree[b].par[i];
    }
    for(ll i = 31;i>=0;i--){
        if(tree[a].par[i] != tree[b].par[i]){
            a = tree[a].par[i];
            b = tree[b].par[i];
        }
    }
    if(a == b)return a;
    if(a == 0||b == 0)return 1LL;
    return tree[a].par[0];
}
void dfs1(ll now){
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par[0])continue;
        dfs1(nxt);
        tree[now].tag += tree[nxt].tag;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i = 0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        tree[a].childs.push_back(b);
        tree[b].childs.push_back(a);
    }
    dfs(1);
    for(ll i = 0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        tree[a].tag++;
        tree[b].tag++;
        tree[tree[lca(a,b)].par[0]].tag --;
        tree[lca(a,b)].tag--;
    }
    /*
    for(ll i = 1;i<=n;i++){
        cout<<i<<':';
        for(ll j = 0;j<4;j++)cout<<tree[i].par[j]<<' ';
        cout<<'\n';
    }
    */
    dfs1(1);
    for(ll i = 1;i<=n;i++)cout<<tree[i].tag<<' ';
    return 0;
}
/*
10 10
6 9
1 5
10 7
7 8
6 8
4 3
2 3
4 10
1 9

1 2
9 10
7 10
7 4
6 1
6 3
7 9
10 9
1 3
7 5
*/
