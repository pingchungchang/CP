#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        if(n==0)return 0;
        int values[n];
        int dp[n][3] = {{0}};
        for(int i =0;i<n;i++){
            cin>>values[i];
        }
        dp[0][0] = values[0];
        dp[0][1] = 2*values[0];
        dp[0][2] = 0;
        for(int i =1;i<n;i++){
            dp[i][0] = values[i]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][1] = values[i]*2+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = dp[i-1][1];
        }
        cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<'\n';
    }
}
