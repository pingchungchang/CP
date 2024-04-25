#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    cout<<max_element(arr,arr+n)-arr+1;
}
