#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    int G = arr[0];
    for(auto &i:arr)G = __gcd(G,i);
    cout<<arr[n-1]/G<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}