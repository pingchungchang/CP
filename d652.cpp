#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n;
void rec(vector<vector<int>> &dp,int s,int e){
    if(e-s<=1){
        dp[s][e] = 0;
        return;
    }
    if(dp[s][e]!= -1)return;
    dp[s][e] = INT_MAX;
    for(int i =s+1;i<e;i++){
        if(dp[s][i] == -1)rec(dp,s,i);
        if(dp[i][e] == -1)rec(dp,i,e);
        dp[s][e] = min(dp[s][e],dp[s][i]+dp[i][e]+arr[i]*arr[s]*arr[e]);
        //printf("%d %d %d %d\n",s,i,e,dp[s][i]+dp[i][e]+arr[i]*arr[s]*arr[e]);
    }
    return;
}

int main(){
    cin>>n;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i =0;i<n;i++)dp[i][i] = 0;
    rec(dp,0,n-1);
    cout<<dp[0][n-1];
}
