#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mod = 1e9+20050909;
const ll inf = 1e18;
struct line{
    ll m,b;
    line(){}
    line(ll a,ll bb){
        m = a,b = bb;
    }
    ll operator()(ll k){
        return m*k+b;
    }
};
struct node{
    line val;
    int pl,pr;
    node(){
        pl = pr = 0;
        val = line(0,-inf);
    }
    ll operator()(ll k){return val(k);}
};
const ll mxn = 1e6+10;
node segtree[mxn*4];
int pp = 0;
int newnode(){
    pp++;
    segtree[pp] = node();
    return pp;
}
void addline(int now,int l,int r,line val){
    if(l == r){
        if(val(l)>segtree[now](l))segtree[now].val = val;
        return;
    }
    int mid = (l+r)>>1;
    if(segtree[now].val.m==val.m&&segtree[now].val.b == val.b)return;
    if(segtree[now](mid)<val(mid))swap(segtree[now].val,val);
    if(segtree[now].val.m>val.m){
        if(!segtree[now].pl)segtree[now].pl = newnode();
        addline(segtree[now].pl,l,mid,val);
    }
    else{
        if(!segtree[now].pr)segtree[now].pr = newnode();
        addline(segtree[now].pr,mid+1,r,val);
    }
    return;
}
ll getval(int now,int l,int r,int p){
    if(!now)return -inf;
    if(l == r)return segtree[now](p);
    int mid = (l+r)>>1;
    if(mid>=p)return max(segtree[now](p),getval(segtree[now].pl,l,mid,p));
    else return max(segtree[now](p),getval(segtree[now].pr,mid+1,r,p));
}
ll arr[mxn],brr[mxn],mrr[mxn];
ll dp[mxn];
ll n;
ll kk;
vector<ll> lpos[mxn],rpos[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>kk;
    for(int i = 0;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++)cin>>brr[i];
    for(int i =1;i<=n;i++)cin>>mrr[i];
    for(int i  = 1;i<=n;i++){
        int s = max(0LL,brr[i]-kk+1),e = brr[i];
        lpos[s].push_back(i);
        rpos[e].push_back(i);
    }
    for(int i = 1;i<=n;i++)dp[i] = -inf;
    for(int i = 0;i<=n;i+= kk){
        pp = 0;
        int root = newnode();
        for(int j = 0;j<kk;j++){
            if(i-j<0)break;
            addline(root,0,mxn,line(-arr[i-j],dp[i-j]));
            for(auto k:lpos[i-j]){
                // if(k == 1)cout<<getval(root,0,mxn,mrr[k])+arr[k]*mrr[k]+mrr[k]<<endl;
                dp[k] = max(dp[k],getval(root,0,mxn,mrr[k])+arr[k]*mrr[k]+mrr[k]);
            }
        }
        pp = 0;
        root = newnode();
        for(int j = 0;j<kk;j++){
            if(i+j>n)break;
            addline(root,0,mxn,line(-arr[i+j],dp[i+j]));
            for(auto k:rpos[i+j]){
                dp[k] = max(getval(root,0,mxn,mrr[k])+arr[k]*mrr[k]+mrr[k],dp[k]);
            }
        }
    }
    // for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';return 0;
    ll total = 0;
    for(int i = 0;i<=n;i++){
        total = (total+dp[i])%mod;
    }
    cout<<total%mod;
}