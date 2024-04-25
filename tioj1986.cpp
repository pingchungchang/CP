#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 3e5+10;
ll arr[mxn];
ll segtree[mxn*4];
ll pref[mxn],cnt[mxn];
ll dp[mxn];
ll sum(ll l,ll r){
    return pref[r]-pref[l-1];
}
ll num(ll l,ll r){
    return cnt[r]-cnt[l-1];
}
ll calc(ll l,ll r){
    return dp[l]-num(l,mxn-1)*(arr[r]-arr[l])
}
int main(){
}