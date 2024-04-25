#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e6+10;
int dp[mxn];
int n,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[k];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+k);
    for(int i = 1;i<mxn;i++){
        for(auto &j:arr){
            if(j>i)break;
            dp[i] = max(dp[i],dp[i-j]^1);
        }
    }
    for(int i = 1;i<=n;i++)cout<<(dp[i] == 1?'W':'L');
    return 0;
}