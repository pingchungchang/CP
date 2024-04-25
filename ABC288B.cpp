#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+k);
    for(int i = 0;i<k;i++)cout<<arr[i]<<'\n';
    return 0;
}