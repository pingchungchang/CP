#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxn = 1e6+10;
const ll mod =1e9+7;
ll dp[mxn];
main(){
    dp[1] = 0,dp[2] = 1;dp[3] = 2;
    for(ll i =4;i<mxn;i++){
        dp[i] = (i-1)*dp[i-1]+(i-1)*dp[i-2];
        dp[i] %= mod;
    }
    int n;
    cin>>n;
    cout<<dp[n];
}

/*
a[i] = x*a[i-1]+(i-2)*a[i-2]
a[1] = 0;
a[2] = 1
a[3] = 2
a[4] = 9
*/