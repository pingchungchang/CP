#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5+10;
int segtree[mxn*4+4];

void modify(int now,int l,int r,int p,int v){
    if(l == r){
        segtree[now] = v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=p)modify(now*2+1,l,mid,p,v);
    else modify(now*2+2,mid+1,r,p,v);
    segtree[now] = __gcd(segtree[now*2+1],segtree[now*2+2]);
    return;
}
int getval(int now,int l,int r,int s,int e){
    if(s<=l&&e>=r)return segtree[now];
    int mid = (l+r)>>1;
    if(mid>=e)return getval(now*2+1,l,mid,s,e);
    else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
    else return __gcd(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        modify(0,0,mxn,i,k);
    }
    int ans = max(getval(0,0,mxn,0,n-2),getval(0,0,mxn,1,n-1));
    for(int i = 1;i<n-1;i++){
        ans = max(ans,__gcd(getval(0,0,mxn,0,i-1),getval(0,0,mxn,i+1,n-1)));
    }
    cout<<ans;
}
