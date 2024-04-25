#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    ll val,stag,dtag;
    node(){
        val = 0,stag = 0,dtag = 0;
    }
};

vector<node> segtree;
ll n,q;
void pv(ll now,ll l,ll r){
    cout<<l<<' '<<r<<' '<<segtree[now].val<<' '<<segtree[now].stag<<' '<<segtree[now].dtag<<endl;
    if(l == r)return;
    ll mid = (l+r)/2;
    pv(now*2+1,l,mid);
    pv(now*2+2,mid+1,r);
}
void push(ll now,ll l,ll r){
    if(l == r)return;
    ll mid = (l+r)/2;
    segtree[now*2+1].stag+= segtree[now].stag;
    segtree[now*2+1].dtag += segtree[now].dtag;
    segtree[now*2+2].stag+= segtree[now].stag+(mid-l+1)*segtree[now].dtag;
    segtree[now*2+2].dtag += segtree[now].dtag;
    segtree[now].stag = 0;
    segtree[now].dtag = 0;
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
    segtree[now].val += (segtree[now*2+1].stag*2+(mid-l)*segtree[now*2+1].dtag)*(mid-l+1)/2+(segtree[now*2+2].stag*2+(r-mid-1)*segtree[now*2+2].dtag)*(r-mid)/2;
    return;
}
void addval(ll s,ll e,ll v,ll now,ll l,ll r){
    push(now,l,r);
    if(s<=l&&e>=r){
        segtree[now].stag += l-s+v;
        segtree[now].dtag ++;
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=e)addval(s,e,v,now*2+1,l,mid);
    else if(mid<s)addval(s,e,v,now*2+2,mid+1,r);
    else{
        addval(s,e,v,now*2+1,l,mid);
        addval(s,e,v,now*2+2,mid+1,r);
    }
    segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
    segtree[now].val += (segtree[now*2+1].stag*2+(mid-l)*segtree[now*2+1].dtag)*(mid-l+1)/2+(segtree[now*2+2].stag*2+(r-mid-1)*segtree[now*2+2].dtag)*(r-mid)/2;
    return;
}

ll getval(ll s,ll e,ll now,ll l,ll r){
    push(now,l,r);
    if(s<=l&&e>=r)return segtree[now].val+(segtree[now].stag*2+segtree[now].dtag*(r-l))*(r-l+1)/2;
    ll mid = (l+r)/2;
    if(mid>=e)return getval(s,e,now*2+1,l,mid);
    else if(mid<s)return getval(s,e,now*2+2,mid+1,r);
    else return getval(s,e,now*2+1,l,mid)+getval(s,e,now*2+2,mid+1,r);
}
int main(){
    cin>>n>>q;
    segtree = vector<node>(n*4,node());
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        addval(i,i,k,0,0,n-1);
    }
    for(ll asd = 0;asd<q;asd++){
        ll t,x,y;
        cin>>t>>x>>y;
        if(t == 1){
            addval(x-1,y-1,1,0,0,n-1);
        }
        else{
            cout<<getval(x-1,y-1,0,0,n-1)<<'\n';
        }
        //pv(0,0,n-1);
        //for(ll i = 0;i<n;i++)cout<<getval(i,i,0,0,n-1)<<' ';cout<<endl;
    }
}
