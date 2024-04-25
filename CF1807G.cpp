#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    ll total = 1;
    if(arr[0] != 1){
        cout<<"NO\n";
        return;
    }
    for(int i = 1;i<n;i++){
        if(total<arr[i]){
            cout<<"NO\n";
            return;
        }
        total += arr[i];
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