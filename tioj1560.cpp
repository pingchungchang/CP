#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 55;
ll dp[mxn][2];
int main(){
    dp[0][1] = 1;
    for(int i = 1;i<mxn;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1]+dp[i-1][0];
    }
    int n;
    while(cin>>n){
        cout<<dp[n][0]+dp[n][1]<<'\n';
    }
    return 0;
}
