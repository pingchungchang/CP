#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll pre =0;
    ll ans = 0;ll arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    for(auto &i:arr){
        ans += (i-pre)*(i-pre);
        pre = i;
    }
    cout<<ans;
}