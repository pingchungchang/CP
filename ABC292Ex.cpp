#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
const ll mxn = 5e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second
struct node{
    ll big,tag;
    node(){
        big = tag = 0;
    }
};
node segtree[mxn*4];
void addval(int now,int l,int r,int s,int e,int v){
    if(l>=s&&e>=r){
        segtree[now].tag += v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)addval(now*2+1,l,mid,s,e,v);
    if(mid<e)addval(now*2+2,mid+1,r,s,e,v);
    segtree[now].big = max(segtree[now*2+1].big+segtree[now*2+1].tag,segtree[now*2+2].big+segtree[now*2+2].tag);
}
ll getbig(int now,int l,int r,ll tar){
    // cout<<l<<','<<r<<','<<segtree[now].big<<','<<segtree[now].tag<<' '<<tar<<endl;
    if(segtree[now].big+segtree[now].tag<tar)return -1;
    if(l == r)return l;
    int mid = (l+r)>>1;
    if(segtree[now*2+1].big+segtree[now*2+1].tag+segtree[now].tag>=tar)return getbig(now*2+1,l,mid,tar-segtree[now].tag);
    else return getbig(now*2+2,mid+1,r,tar-segtree[now].tag);
}
ll bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
}
ll getval(int p){
    ll re = 0;
    for(;p>0;p-= p&-p)re += bit[p];
    return re;
}

ll arr[mxn];
ll n,b,q;

main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>b>>q;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        modify(i,arr[i]);
        // cout<<i<<":"<<b<<','<<arr[i]-b<<endl;
        addval(0,1,n,i,n,arr[i]-b);
    }
    while(q--){
        int ta,tb;
        cin>>ta>>tb;
        modify(ta,tb-arr[ta]);
        addval(0,1,n,ta,n,tb-arr[ta]);
        arr[ta] = tb;
        auto pos = getbig(0,1,n,0);
        // cout<<ta<<','<<tb<<":"<<pos<<endl;
        if(pos == -1)cout<<fixed<<setprecision(10)<<((double)getval(n))/n<<'\n';
        else cout<<fixed<<setprecision(10)<<((double)getval(pos))/pos<<'\n';
    }
    return 0;
}