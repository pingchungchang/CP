#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    reverse(arr,arr+n);
    int big = 1e9+10,cnt = 0,ans = 0;
    for(auto &i:arr){
        if(big<=i){
            big = i;
            cnt++;
        }
        else{
            big = i;
            cnt = 0;
        }
        ans = max(ans,cnt);
    }
    cout<<ans;
}