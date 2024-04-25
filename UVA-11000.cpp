#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> topdown(vector<pair<long long,long long>> &dp,long long n){
    if(dp[n].first == -1){
        pair<long long,long long> last = topdown(dp,n-1);
        dp[n].first = last.second+1;
        dp[n].second = last.second+last.first;
    }
    return dp[n];
}

int main(){
    long long n;
    vector<pair<long long,long long>> dp(999,make_pair(-1,-1));
    dp[0] = make_pair(1,0);
    dp[1] = make_pair(1,1);
    dp[2] = make_pair(2,2);
    while(cin>>n){
        if(n<=-1)return 0;
        if(dp[n].first == -1){
            topdown(dp,n);
        }
        printf("%lld %lld\n",dp[n].second,dp[n].second+dp[n].first);
    }
}