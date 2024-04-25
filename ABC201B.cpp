#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int,string> arr[n];
    for(auto &i:arr){
        cin>>i.second>>i.first;
    }
    sort(arr,arr+n);
    cout<<arr[n-2].second;
}