#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto  &i:arr)cin>>i;
    sort(arr,arr+n);
    if(arr[0] == arr[n-1]){
        cout<<n/2<<'\n';
        return;
    }
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(i != n-1&&arr[i] == arr[i+1])continue;
        ans = max(ans,1LL*(n-i-1)*(i+1));
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}