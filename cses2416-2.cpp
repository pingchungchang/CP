#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll big,tag,small,val;
    node(){
        big = 0,tag = 0,small = 0,val = 0;
    }
};

vector<node>segtree;
vector<ll> pref;
vector<ll> arr;
ll n,q;
void maketree(ll p,ll v,ll now,ll l,ll r){
    segtree[now].val = 0,segtree[now].tag = 0,segtree[now].big = 0,segtree[now].small = 0;
    if(l == r){
        segtree[now].val = v;
        segtree[now].big = v;
        segtree[now].small = v;
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=pos)maketree(p,v,now*2+1,l,mid);
    else maketree(p,v,now*2+2,mid+1,r);
    if(segtree[now*2+1].big>segtree[now*2+2].big){
        segtree[now*2+1].tag = segtree[now*2+1].big;
        segtree[now].val = segtree[now*2+1].val+segtree[now*2+1].tag*(r-mid);
    }
    else if(segtree[now*2+1].big<=arr[mid+1]){
        segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
    }
    else{
        segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val+calc(segtree[now*2+1].big,now*2+2,mid+1,r);
        segtree[now*2+2].small = segtree[now*2+1].big;
    }
    segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
    return;
}
ll sum(ll s,ll e){
    if(s == 0LL)return pref[e];
    else return pref[e]-pref[s-1];
}
int main(){
    cin>>n>>q;
    arr = vector<ll>(n);
    pref = vector<ll>(n);
    segtree = vector<node>(n*4,node());
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
        maketree(i,arr[i],0,0,n-1);
        pref[i] = arr[i]+(i>0?pref[i-1]:0LL);
    }
}
/*
int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    for(int i = 0;i<q;i++){
        int s,e;
        cin>>s>>e;
        s--,e--;
        ll ans = 0;
        ll big = v[s];
        for(ll j = s+1;j<=e;j++){
            ans += max(0LL,big-v[j]);
            big = max(big,v[j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
*/
