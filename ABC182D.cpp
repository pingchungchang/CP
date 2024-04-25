#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    ll big[n];
    fill(big,big+n,0LL);
    if(arr[0] > 0)big[0] = arr[0];
    for(int i = 1;i<n;i++){
        arr[i] += arr[i-1];
        big[i] = max(big[i-1],arr[i]);
    }
    ll ans = 0;
    ll now = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,now+big[i]);
        now += arr[i];
    }
    cout<<ans;
}