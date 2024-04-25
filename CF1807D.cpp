#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n,q;
    cin>>n>>q;
    ll arr[n+1];
    arr[0] = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    ll total = arr[n];
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        ll dif = arr[r]-arr[l-1]-k*(r-l+1);
        dif = abs(dif);
        if((total-dif)&1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}