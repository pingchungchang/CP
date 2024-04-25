#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    prev_permutation(arr,arr+n);
    for(auto &i:arr)cout<<i<<' ';
}