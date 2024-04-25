#include <bits/stdc++.h>
using namespace std;

#define mxn (int)1e4
int main(){
    int dp[mxn];
    int arr[] = {1,5,10,25,50};
    dp[0] = 1;
    for(int j = 0;j<5;j++){
        for(int i = arr[j];i<8000;i++){
            dp[i] += dp[i-arr[j]];
        }
    }
    int n;
    while(cin>>n)cout<<dp[n]<<'\n';
}
