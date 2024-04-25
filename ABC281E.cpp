#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
const ll inf = 1e9+10;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct node{
    ll l,r,sum,cnt;
    node* pl,*pr;
    node(){
        l = r = sum = cnt = 0;
        pl = pr = 0;
    }
    node(ll lll,ll rr){
        l = lll,r = rr;
        sum = cnt = 0;
        pl = pr = 0;
    }
};
node* segtree = new node(0,inf);
void addval(node* now,ll val,ll cc){
    if(now->l == now->r){
        now->sum += cc*val;
        now->cnt+=cc;
        return;
    }
    ll mid = (now->l+now->r)>>1;
    if(!now->pl){
        now->pl = new node(now->l,mid);
        now->pr = new node(mid+1,now->r);
    }
    if(mid>=val){
        addval(now->pl,val,cc);
    }
    else addval(now->pr,val,cc);
    now->sum = now->pl->sum+now->pr->sum;
    now->cnt = now->pl->cnt+now->pr->cnt;
    return;
}
ll getval(node* now,ll cc){
    if(cc == 0)return 0LL;
    if(now->l == now->r){
        if(now->cnt == 0)return 0;
        else return now->sum/now->cnt*cc;
    }
    else if(now->cnt == cc)return now->sum;
    ll mid = (now->l+now->r)>>1;
    if(now->pl->cnt>=cc)return getval(now->pl,cc);
    else return now->pl->sum+getval(now->pr,cc-now->pl->cnt);
}
void dfs(node* now){
    if(!now)return;
    if(now->l == now->r&&now->cnt != 0)cout<<now->l<<' '<<now->cnt<<',';
    dfs(now->pl);dfs(now->pr);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans[n];
    ll total = 0;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<m;i++){
        addval(segtree,arr[i],1);
    }
    // return 0;
    cout<<getval(segtree,k)<<' ';
    for(int i = 0;i+m<n;i++){
        addval(segtree,arr[i],-1);
        addval(segtree,arr[i+m],1);
        cout<<getval(segtree,k)<<' ';
        // dfs(segtree);
        // cout<<'\n';
    }
}