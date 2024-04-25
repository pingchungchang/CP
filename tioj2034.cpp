#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+n);
    bool flag = true;
    for(int i = 1;i<n;i++)if(arr[i] != arr[i-1]+1)flag = false;
    cout<<arr[0]<<' '<<arr[n-1]<<' '<<(flag?"yes":"no");
    return 0;
}