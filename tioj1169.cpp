#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
struct node{
    int pl,pr;
    ll lsum,rsum,big;
};

node segtree[mxn*100];
int pp = 0;
ll cols[1+(1LL<<24)];
int arr[mxn];
int newnode(ll s,ll e){
    pp++;
    segtree[pp].pl = segtree[pp].pr = 0;
    segtree[pp].lsum = segtree[pp].rsum = segtree[pp].big = e-s+1;
    return pp;
}

void modify(int now,int l,int r,int p,int v){
    if(l == r){
        if(v == -1)segtree[now].lsum = segtree[now].rsum = segtree[now].big = 1;
        else segtree[now].lsum = segtree[now].rsum = segtree[now].big = 0;
        return;
    }
    int mid = (l+r)>>1;
    if(!segtree[now].pl){
        segtree[now].pl = newnode(l,mid);
        segtree[now].pr = newnode(mid+1,r);
    }
    if(mid>=p)modify(segtree[now].pl,l,mid,p,v);
    else modify(segtree[now].pr,mid+1,r,p,v);
    segtree[now].big = max({segtree[segtree[now].pl].big,segtree[segtree[now].pr].big,segtree[segtree[now].pl].rsum+segtree[segtree[now].pr].lsum});
    segtree[now].lsum = segtree[segtree[now].pl].lsum;
    if(segtree[segtree[now].pl].lsum == mid-l+1)segtree[now].lsum += segtree[segtree[now].pr].lsum;
    segtree[now].rsum = segtree[segtree[now].pr].rsum;
    if(segtree[segtree[now].pr].rsum == r-mid)segtree[now].rsum += segtree[segtree[now].pl].rsum;
    return;
}

pair<int,pii> getval(int now,int l,int r,int s,int e){
    if(!now){
        int d = min(r,e)-max(l,s)+1;
        return make_pair(d,make_pair(d,d));
    }
    if(l>=s&&e>=r){
        return make_pair(segtree[now].big,make_pair(segtree[now].lsum,segtree[now].rsum));
    }
    int mid = (l+r)>>1;
    if(mid>=e)return getval(segtree[now].pl,l,mid,s,e);
    else if(mid<s)return getval(segtree[now].pr,mid+1,r,s,e);
    else{
        auto r1 = getval(segtree[now].pl,l,mid,s,e);
        auto r2 = getval(segtree[now].pr,mid+1,r,s,e);
        pair<int,pii> re;
        re.fs = max({r1.fs,r2.fs,r1.sc.sc+r2.sc.fs});
        re.sc = make_pair(r1.sc.fs,r2.sc.sc);
        if(r1.sc.fs == mid-l+1)re.sc.fs += r2.sc.fs;
        if(r2.sc.sc == r-mid)re.sc.sc += r1.sc.sc;
        return re;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q,C;
    cin>>n>>q>>C;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        arr[i] = k;
        if(!cols[k])cols[k] = newnode(0,n-1);
        modify(cols[k],0,n-1,i,1);
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 0){
            int p,k;
            cin>>p>>k;
            modify(cols[arr[p]],0,n-1,p,-1);
            if(!cols[k])cols[k] = newnode(0,n-1);
            modify(cols[k],0,n-1,p,1);
            arr[p] = k;
        }
        else{
            ll s,e,k;
            cin>>s>>e>>k;
            e--;
            if(!cols[k])cout<<e-s+1<<'\n';
            else cout<<getval(cols[k],0,n-1,s,e).fs<<'\n';
        }
    }
}