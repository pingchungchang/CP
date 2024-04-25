#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[10];
    int sum = 0;
    for(auto &i:arr){
        cin>>i;
        sum +=i;
    }
    sum /=4;
    // cout<<sum<<endl;
    sort(arr,arr+10);
    int ans[5];
    ans[2] = sum-arr[0]-arr[9];
    ans[0] = arr[1]-ans[2];
    ans[1] = arr[0]-ans[0];
    ans[4] = arr[8]-ans[2];
    ans[3] = sum-ans[0]-ans[1]-ans[2]-ans[4];
    // sort(ans,ans+5);
    for(auto &i:ans)cout<<i<<' ';
    return 0;
}