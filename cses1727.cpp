#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define ld long double
#define ll long long
const ll mxn = 101;
ld dp[2][mxn];
int main(){
    srand(time(NULL));
    int n,k;
    cin>>n>>k;
    short roll = 0;
    for(int i = 1;i<=k;i++)dp[roll][i] = 1;
    for(int i = 1;i<n;i++){
        roll ^= 1;
        for(auto &j:dp[roll])j = 0;
        for(int j = 1;j<=k;j++){
            for(int l = 1;l<=j;l++)dp[roll][j] += dp[roll^1][l];
            for(int l = j+1;l<=k;l++)dp[roll][l] += dp[roll^1][l];
        }
    }
    ld total = 0,cnt = 0;
    for(int i = 1;i<=k;i++){
        total += dp[roll][i];
        cnt += dp[roll][i]*i;
    }
    cout<<fixed<<setprecision(6)<<cnt/total;
}