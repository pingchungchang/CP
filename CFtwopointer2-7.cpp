#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e5+10;
ll segtree[mxn*4+4];
void modify(int now,int l,int r,ll p,ll v){
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
ll getval(int now,int l,int r,int s,int e){
    if(l>=s&&e>=r)return segtree[now];
    int mid = (l+r)>>1;
    if(mid>=e)return getval(now*2+1,l,mid,s,e);
    else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
    else return __gcd(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int main(){
    int n;
    cin>>n;
    int p = 0;
    ll arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        modify(0,0,mxn,i,arr[i]);
    }
    int ans = 1e9;
    for(int i = 0;i<n;i++){
        if(p<i)p = i;
        while(p<n&&getval(0,0,mxn,i,p) != 1)p++;
        if(p == n){
            break;
        }
        ans = min(ans,p-i+1);
    }
    if(ans>n)cout<<-1;
    else cout<<ans;
}