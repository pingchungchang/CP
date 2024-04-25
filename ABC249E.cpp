#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mxn = 1e3+10;
ll mod,n;
int main(){
    cin>>n>>mod;
    vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(mxn,vector<ll>(mxn,0LL)));
    int now = 0,pre= 1;
    dp[now][0][0] = 1;
    //dp[anslen][times]
    for(int i = 0;i)
}
