#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int total = 0;
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++)for(int j = i+1;j<n;j++){
        total += arr[i]*arr[j];
    }
    cout<<total;
}