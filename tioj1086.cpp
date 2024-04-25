#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll dp[21];
    dp[1] = 0;
    dp[2] = 1;
    for(ll i = 3;i<=20;i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    int n;
    while(cin>>n){
        if(n == 0)return 0;
        cout<<dp[n]<<'\n';
    }
}
