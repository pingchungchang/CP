#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e5+10;
pll segtree[mxn*4+4];
int arr[mxn];

void setval(int now,int l,int r,int p,ll v){
    if(l == r){
        segtree[now].fs = segtree[now].sc = v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=p)setval(now*2+1,l,mid,p,v);
    else setval(now*2+2,mid+1,r,p,v);
    segtree[now].fs = max(segtree[now*2+1].fs,segtree[now*2+2].fs);
    segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
    return;
}

void modify(int now,int l,int r,int s,int e,int v){
    if(l == r){
        segtree[now].fs = segtree[now].sc = segtree[now].sc%v;
        return;
    }
    int mid = (l+r)>>1;
    if(l>=s&&e>=r){
        if(segtree[now].fs<v)return;
        if(segtree[now*2+1].fs>=v)modify(now*2+1,l,mid,s,e,v);
        if(segtree[now*2+2].fs>=v)modify(now*2+2,mid+1,r,s,e,v);
        segtree[now].fs = max(segtree[now*2+1].fs,segtree[now*2+2].fs);
        segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
        return;
    }
    if(mid>=s)modify(now*2+1,l,mid,s,e,v);
    if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
    segtree[now].fs = max(segtree[now*2+1].fs,segtree[now*2+2].fs);
    segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
    return;
}

ll getval(int now,int l,int r,int s,int e){
    if(l>=s&&e>=r)return segtree[now].sc;
    int mid = (l+r)>>1;
    if(mid>=e)return getval(now*2+1,l,mid,s,e);
    else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
    else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        setval(0,1,n,i,arr[i]);
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int s,e;
            cin>>s>>e;
            cout<<getval(0,1,n,s,e)<<'\n';
        }
        else if(t == 2){
            int s,e,v;
            cin>>s>>e>>v;
            modify(0,1,n,s,e,v);
        }
        else{
            int k,x;
            cin>>k>>x;
            setval(0,1,n,k,x);
        }
    }
    return 0;
}