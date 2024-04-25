#include <bits/stdc++.h>
using namespace std;
long long finding(vector<long long> &dp,long long n){
    if(dp[n] == -1){
        dp[n] = finding(dp,n-1)+finding(dp,n-2);
    }
    return dp[n];
}
int main(){
    long long n;
    vector<long long> dp(51,-1);
    while(cin>>n){
        if(n == 0) return 0;
        dp[1] = 1;
        dp[2] = 2;
        cout<<finding(dp,n)<<endl;
    }

}