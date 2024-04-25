#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    ll val;
    ll tag;
    node(){
        val = 0;
        tag = 0;
    }
};
vector<node> segtree;
void push(ll now,ll l,ll r){
    ll mid = (l+r)/2;
    if(segtree[now].tag == 0)return;
    segtree[now*2+1].tag = segtree[now].tag;
    segtree[now*2+1].val = segtree[now].tag*(mid-l+1);
    segtree[now*2+2].tag = segtree[now].tag;
    segtree[now*2+2].val = (r-mid)*segtree[now].tag;
    segtree[now].tag = 0;
    return;
}
void changeval(ll s,ll e,ll v,ll now,ll l,ll r){
    //cout<<s<<' '<<e<<' '<<v<<' '<<l<<' '<<r<<'\n';
    if(s<=l&&e>=r){
        segtree[now].tag = v;
        segtree[now].val = (r-l+1)*v;
        return;
    }
    push(now,l,r);
    ll mid = (l+r)/2;
    if(mid>=e)changeval(s,e,v,now*2+1,l,mid);
    else if(mid<s)changeval(s,e,v,now*2+2,mid+1,r);
    else{
        changeval(s,e,v,now*2+1,l,mid);
        changeval(s,e,v,now*2+2,mid+1,r);
    }
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
}
void pv(ll now,ll l,ll r){
    cout<<l<<' '<<r<<' '<<segtree[now].val<<'\n';
    ll mid = (l+r)/2;
    if(l == r)return;
    pv(now*2+1,l,mid);
    pv(now*2+2,mid+1,r);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q;
    cin>>n>>q;
    segtree = vector<node>(n*4LL,node());
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        changeval(i,i,k,0,0,n-1);
    }
    for(ll i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 2){
            ll x;
            cin>>x;
            changeval(0,n-1,x,0,0,n-1);
        }
        else{
            ll a,x;
            cin>>a>>x;
            changeval(a-1,a-1,x,0,0,n-1);
        }
        //pv(0,0,n-1);
        cout<<segtree[0].val<<'\n';
    }
}
