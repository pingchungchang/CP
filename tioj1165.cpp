#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int arr[3];
    while(cin>>arr[0]>>arr[1]>>arr[2]){
        sort(arr,arr+3);
        if(arr[2] == arr[1]+arr[0])cout<<"Good Pair\n";
        else cout<<"Not Good Pair\n";
    }
    return 0;
}