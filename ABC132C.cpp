#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    if(arr[n/2] == arr[n/2-1])cout<<0;
    else cout<<arr[n/2]-arr[n/2-1];
}