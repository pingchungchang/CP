#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n*5];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n*5);
    long double total = 0;
    for(int i = n;i<n*4;i++){
        total += arr[i];
    }
    cout<<fixed<<setprecision(10)<<total/(n*3);
}