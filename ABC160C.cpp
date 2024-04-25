#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans = k;
    for(int i = 1;i<n;i++){
        ans = min(ans,k-(arr[i]-arr[i-1]));
    }
    ans = min(ans,k-(k-arr[n-1]+arr[0]));
    cout<<ans;
}