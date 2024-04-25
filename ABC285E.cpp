#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 5050;

ll dp[mxn];

int main(){
    int n;
    cin>>n;
    ll pref[n+1];
    pref[0] = 0;
    for(int i = 1;i<=n;i++){
        cin>>pref[i];
        pref[i] += pref[i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            dp[j] = max(dp[j],dp[j-i]+pref[i/2]+pref[(i-1)/2]);
        }
    }
    cout<<dp[n];
}