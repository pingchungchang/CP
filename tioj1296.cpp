#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n = 20;
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;i++)dp[i] = (dp[i-1]*(4*i-2))/(i+1);
    // for(auto &i:dp)cout<<i<<' ';cout<<endl;
    while(cin>>n)cout<<dp[n]<<'\n';
    return 0;
}