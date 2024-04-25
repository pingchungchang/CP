#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
ll n,k;
const int mxn = 3030;
ll arr[mxn];
ll pref[mxn],cnt[mxn];
ll dp[2][mxn];
ll segtree[mxn*4];
bool roll = 0;

ll sum(ll a,ll b){
    return pref[b]-pref[a-1];
}
ll calc(ll a,ll b){
    if(a>=b)return 1e18;
    auto mid = (a+b)>>1;
    return dp[roll^1][a]-(b-a)*(cnt[n]-cnt[b])-(sum(mid+1,b)-(cnt[b]-cnt[mid])*a)
    +(cnt[b]-cnt[mid])*b-sum(mid+1,b);
}
void modify(int now,int l,int r,int p){
    if(!segtree[now]){
        segtree[now] = p;
        return;
    }
    if(l == r){
        if(calc(p,r)<calc(segtree[now],r))segtree[now] = p;
        return;
    }
    int mid = (l+r)>>1;
    if(p>=mid){
        modify(now*2+2,mid+1,r,p);
        return;
    }
    if(calc(p,mid)<calc(segtree[now],mid))swap(segtree[now],p);
    if(p>segtree[now])modify(now*2+2,mid+1,r,p);
    else modify(now*2+1,l,mid,p);
}
ll getval(int now,int l,int r,int p){
    if(!segtree[now])return 1e18;
    if(l == r)return calc(segtree[now],p);
    int mid = (l+r)>>1;
    if(mid>=p)return min(calc(segtree[now],p),getval(now*2+1,l,mid,p));
    else return min(calc(segtree[now],p),getval(now*2+2,mid+1,r,p));
}
void pv(int now,int l,int r){
    if(!segtree[now])return;
    int mid = (l+r)>>1;
    cout<<l<<' '<<r<<":"<<segtree[now]<<endl;
    pv(now*2+1,l,mid);
    pv(now*2+2,mid+1,r);
    return;
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        pref[i] = arr[i]*i;
        cnt[i] += arr[i];
        pref[i] += pref[i-1];
        cnt[i] += cnt[i-1];
    }
    for(int i = 1;i<=n;i++){
        dp[roll][i] = cnt[i]*i-sum(1,i)+sum(i+1,n)-(cnt[n]-cnt[i])*i;
    }
    // for(int i = 1;i<=n;i++)cout<<pref[i]<<' ';cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<cnt[i]<<' ';cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<dp[roll][i]<<' ';cout<<endl;
    for(int i = 1;i<k;i++){
        roll ^=1;
        memset(segtree,0,sizeof(segtree));
        modify(0,1,n,i);
        for(int j = i+1;j<=n;j++){
            dp[roll][j] = getval(0,1,n,j);
            modify(0,1,n,j);
            // cout<<j<<":"<<endl;pv(0,1,n);cout<<endl;
            // if(j == 5)pv(0,1,n);return 0;
        }
        // pv(0,1,n);
        // for(int j = 1;j<=n;j++)cout<<dp[roll][j]<<' ';
    }
    // cout<<endl;
    cout<<*min_element(dp[roll]+k,dp[roll]+n+1);
}
