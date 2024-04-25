#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n+1];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    arr[n] = arr[0];
    ll now = 0,pre = 0;
    for(int i = 1;i<=n;i++){
        now = pre+max(arr[i],arr[i-1])+1;
        if(now>m){
            cout<<"NO\n";
            return;
        }
        pre = now;
    }
    cout<<"YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}