#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll sum = 0;
    ll arr[n];
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr,arr+n);
    sum -= arr[n-1];
    if(sum>=arr[n-1]-1){
        if(arr[n-1] != 0)cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    else{
        cout<<arr[n-1]-sum<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;for(int i = 0;i<t;i++)solve();
}
