#include <iostream>
#include <vector>

using namespace std;

int recursive(int n,vector<int> &dp){
    if(dp[n] != -1) return dp[n];
    else {
        dp[n] = recursive(n-1,dp)+n*n;
        return dp[n];
    }
}
int main(){
    int n;
    vector<int> dp(101,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 5;
    while(cin>>n){
        if(n==0) return 0;
        cout<<recursive(n,dp)<<"\n";
    }
}
