#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+3);
    if(arr[1]-arr[0] == arr[2]-arr[1])cout<<"Yes";
    else cout<<"No";
}