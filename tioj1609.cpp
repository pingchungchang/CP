#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    for(auto &i:arr)cout<<i<<' ';return 0;
}