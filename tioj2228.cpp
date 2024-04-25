#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll


const ll mxn = 6e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second

pll segtree[mxn*4];

struct node{
    ll y;
    ll s,e,val;
    node(){}
    node(ll ss,ll ee,ll yy,ll vv){
        s = ss,e = ee,y = yy, val = vv;
    }
    bool operator<(node &b){
        return y<b.y;
    }
};
void modify(int now,int l,int r,int s,int e,int v){
    if(l>=s&&e>=r){
        segtree[now].sc += v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)modify(now*2+1,l,mid,s,e,v);
    if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
    segtree[now].fs = max(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
}
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<node> v;
    vector<ll> all;
    for(int i = 0;i<n;i++){
        pll tmp;
        ll r;
        ll w;
        cin>>tmp.fs>>tmp.sc>>r>>w;
        tmp = {tmp.fs-tmp.sc,tmp.fs+tmp.sc};
        v.push_back(node(tmp.sc-r,tmp.sc+r,tmp.fs-r,w));
        v.push_back(node(tmp.sc-r,tmp.sc+r,tmp.fs+r+1,-w));
        all.push_back(tmp.sc-r);
        all.push_back(tmp.sc+r);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:v){
        i.s = lower_bound(all.begin(),all.end(),i.s)-all.begin();
        i.e = lower_bound(all.begin(),all.end(),i.e)-all.begin();
    }
    sort(v.begin(),v.end());
    ll now = 0;
    ll ans = 0;
    for(auto &i:v){
        if(now != i.y){
            ans = max(ans,segtree[0].fs+segtree[0].sc);
            now = i.y;
        }
        modify(0,0,mxn,i.s,i.e,i.val);
    }
    cout<<ans;
}