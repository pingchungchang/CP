#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("popcnt")
#define int ll
vector<ll> sq;
const int mxn = 1LL<<18;
int cnt[mxn];
void solve(){
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i =1 ;i<=n;i++)arr[i] ^= arr[i-1];
    ll total = 0;
    cnt[0] = 1;
    for(int i= 1;i<=n;i++){
        for(auto &j:sq){
            total += cnt[j^arr[i]];
        }
        cnt[arr[i]]++;
    }
    for(auto &i:arr)cnt[i] = 0;
    cnt[0] = 0;
    cout<<1LL*n*(n+1)/2-total<<'\n';
    return;
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 0;i*i<(1LL<<18);i++)sq.push_back(i*i);
    int t;
    cin>>t;
    while(t--)solve();
}