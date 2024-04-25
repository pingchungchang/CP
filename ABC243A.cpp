#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3],t;
    cin>>t;
    for(auto &i:arr)cin>>i;
    t %= arr[0]+arr[1]+arr[2];
    if(t<arr[0])cout<<"F";
    else if(t<arr[0]+arr[1])cout<<"M";
    else cout<<"T";
}