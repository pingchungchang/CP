#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<long long> dp(10001,-1);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    while(cin>>n){
        if(dp[n] == -1){
            for(int i = 1;i<=n;i++){
                if(dp[i] == -1){
                    dp[i] = LONG_LONG_MAX;
                    for(int j =2;j<i;j++){
                        long long now = 2*dp[j]+((long long)pow(2,(i-j)))-1;
                        if(now<dp[i]&&now>0) dp[i] = now;
                    }
                }
            }
        }
        printf("%lld\n",dp[n]);
    }
}//big ints fail