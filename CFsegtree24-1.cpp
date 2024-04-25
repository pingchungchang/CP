#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll stag,atag,val;
    node(){
        stag = -1,atag = 0,val = 0;
    }
};
ll n,m;
vector<node> segtree;
void pv(ll now,ll l,ll r){
    cout<<l<<' '<<r<<' '<<segtree[now].stag<<' '<<segtree[now].atag<<' '<<segtree[now].val<<'\n';
    if(l == r)return;
    ll mid = (l+r)/2;
    pv(now*2+1,l,mid);
    pv(now*2+2,mid+1,r);
}
void push(ll now,ll l, ll r){
    ll mid = (l+r)/2;
    if(l == r)return;
    if(segtree[now].stag != -1){
        segtree[now*2+1].stag = segtree[now].stag;
        segtree[now*2+1].atag = segtree[now].atag;
        segtree[now*2+1].val = segtree[now].stag*(mid-l+1);
        segtree[now*2+2].stag = segtree[now].stag;
        segtree[now*2+2].val = segtree[now].stag*(r-mid);
        segtree[now*2+2].atag = segtree[now].atag;
    }
    else if(segtree[now].atag != 0){
        segtree[now*2+1].atag += segtree[now].atag;
        segtree[now*2+2].atag += segtree[now].atag;
    }
    else return;
    segtree[now].stag = -1;
    segtree[now].atag = 0;
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val+segtree[now*2+1].atag*(mid-l+1)+segtree[now*2+2].atag*(r-mid);
    return;
}
ll getval(ll s,ll e,ll now,ll l,ll r){
    push(now,l,r);
    if(s<=l&&e>=r){
        return segtree[now].val+segtree[now].atag*(r-l+1);
    }
    ll mid = (l+r)/2;
    if(mid<s)return getval(s,e,now*2+2,mid+1,r);
    else if(mid>=e)return getval(s,e,now*2+1,l,mid);
    else return getval(s,e,now*2+1,l,mid)+getval(s,e,now*2+2,mid+1,r);
}
void addval(ll s,ll e,ll v,ll now,ll l,ll r){
    push(now,l,r);
    if(s<=l&&e>=r){
        segtree[now].atag += v;
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=e)addval(s,e,v,now*2+1,l,mid);
    else if(mid+1<=s)addval(s,e,v,now*2+2,mid+1,r);
    else{
        addval(s,e,v,now*2+1,l,mid);
        addval(s,e,v,now*2+2,mid+1,r);
    }
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+1].atag*(mid-l+1)+segtree[now*2+2].val+segtree[now*2+2].atag*(r-mid);
    return;
}
void setval(ll s,ll e,ll v,ll now,ll l,ll r){
    push(now,l,r);
    if(s<=l&&e>=r){
        segtree[now].val = v*(r-l+1);
        segtree[now].atag = 0;
        segtree[now].stag = v;
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=e)setval(s,e,v,now*2+1,l,mid);
    else if(mid+1<=s)setval(s,e,v,now*2+2,mid+1,r);
    else{
        setval(s,e,v,now*2+1,l,mid);
        setval(s,e,v,now*2+2,mid+1,r);
    }
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+1].atag*(mid-l+1)+segtree[now*2+2].val+segtree[now*2+2].atag*(r-mid);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    segtree = vector<node>(n*4,node());

    for(int i = 0;i<m;i++){
        int t;
        cin>>t;
        if(t == 2){
            ll x,y,v;
            cin>>x>>y>>v;
            y--;
            addval(x,y,v,0,0,n-1);
        }
        else if(t == 1){
            ll x,y,v;
            cin>>x>>y>>v;
            y--;
            setval(x,y,v,0,0,n-1);
        }
        else{
            ll x,y;
            cin>>x>>y;
            y--;
            cout<<getval(x,y,0,0,n-1)<<'\n';
        }
    }
    return 0;
}
