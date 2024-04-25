#include <bits/stdc++.h>
using namespace std;

const int mod = 2012;
int main(){
    int dp[10010] = {};
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3;i<=10000;i++){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i]%= mod;
    }
    int n;
    while(cin>>n)cout<<dp[n]<<'\n';
}
