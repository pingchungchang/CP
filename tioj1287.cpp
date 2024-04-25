#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e6+10;
int arr[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        for(int i = 0;i<n;i++)cout<<arr[i]<<' ';cout<<'\n';
    }
}