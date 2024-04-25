#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3];
    int b;
    cin>>arr[0]>>arr[1]>>arr[2];
    b = arr[1];
    sort(arr,arr+3);
    if(b == arr[1])cout<<"Yes";
    else cout<<"No";
}
