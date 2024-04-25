#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,h;
    cin>>n>>h;
    ll nh= h;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    ll ans = 0;

    ll p = 0;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 3;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    ans = max(ans,p);

    p = 0;
    nh = h;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 3;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    ans = max(ans,p);

    p = 0;
    nh = h;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 3;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    nh *= 2;
    while(p<n&&arr[p]<nh){
        nh += arr[p]/2;
        p++;
    }
    ans = max(ans,p);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}