#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;
const int mxn = 1010;
const int mxn2 = 1e6+10;
ll cnt[mxn*mxn],pref[mxn*mxn];
ll dp[2][mxn],segtree[mxn*4];
ll arr[mxn];
bool roll = 0;
ll n,k;
ll sum(ll l,ll r){return pref[r]-pref[l-1];}
ll calc(ll l,ll r){
    if(l >=mxn||r>=mxn)return inf;
    if(r<=l)return inf;
    int mid = (arr[l]+arr[r])>>1;
    return dp[roll^1][l]-(n-r)*(arr[r]-arr[l])-2*sum(mid+1,arr[r])+(cnt[arr[r]]-cnt[mid])*(arr[l]+arr[r]);
}
void modify(int now,int l,int r,ll pos){
    // cout<<l<<' '<<r<<':'<<pos<<' '<<segtree[now]<<endl;
    if(l == r){
        if(calc(pos,l)<calc(segtree[now],l))segtree[now] = pos;
        return;
    }
    if(pos == segtree[now])return;
    int mid = (l+r)>>1;
    if(mid<=pos){
        modify(now*2+2,mid+1,r,pos);
        return;
    }
    if(calc(segtree[now],mid)>calc(pos,mid)){
        swap(segtree[now],pos);
    }
    if(segtree[now]<pos)modify(now*2+2,mid+1,r,pos);
    else modify(now*2+1,l,mid,pos);
}
ll getval(int now,int l,int r,int pos){
    if(l == r){
        return calc(segtree[now],pos);
    }
    int mid = (l+r)>>1;
    if(mid>=pos)return min(calc(segtree[now],pos),getval(now*2+1,l,mid,pos));
    else return min(calc(segtree[now],pos),getval(now*2+2,mid+1,r,pos));
}
void dfs(int now,int l,int r){
    // if(segtree[now]>mxn)return;
    cout<<l<<' '<<r<<' '<<segtree[now]<<endl;
    if(l == r)return;
    int mid = (l+r)>>1;
    dfs(now*2+1,l,mid);
    dfs(now*2+2,mid+1,r);
}
int main(){
    cin>>n>>k;
    k = min(k,n);
    arr[1] = 1;
    pref[1] = cnt[1] = 1;
    for(int i = 2;i<=n;i++){
        cin>>arr[i];
        arr[i]++;
        pref[arr[i]]+=arr[i];
        cnt[arr[i]]++;
    }
    for(int i = 1;i<mxn*mxn;i++){
        pref[i] += pref[i-1];
        cnt[i] += cnt[i-1];
    }
    fill(dp[roll],dp[roll]+n+1,inf);
    sort(arr+1,arr+n+1);
    for(int i = 1;i<=n;i++){
        dp[roll][i] = i*arr[i]-sum(1,arr[i])+sum(arr[i]+1,mxn2)-(n-i)*arr[i];
        // cout<<dp[roll][i]<<' ';
    }
    // return 0;
    // cout<<calc(3,2)<<' '<<calc(3,3)<<endl;
    for(int i = 1;i<k;i++){
        roll ^= 1;
        fill(segtree,segtree+mxn*4,inf);
        fill(dp[roll],dp[roll]+mxn,inf);
        modify(0,1,n,i);
        // cout<<dp[roll^1][i]<<endl;
        // dfs(0,1,n);
        for(int j = i+1;j<=n;j++){
            dp[roll][j] = getval(0,1,n,j);
            modify(0,1,n,j);
        }
        // for(int j = 1;j<=n;j++)cout<<dp[roll][j]<<' ';cout<<endl;
    }
    cout<<*min_element(dp[roll],dp[roll]+n+1);
}