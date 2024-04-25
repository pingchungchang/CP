#include <bits/stdc++.h>
using namespace std;

void solve(){
    int arr[3];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+3);
    cout<<arr[1]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}