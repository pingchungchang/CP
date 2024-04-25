#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n,k;
void solve(){
    k = n-k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    nth_element(arr,arr+k,arr+n);
    cout<<arr[k]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>k)solve();
}