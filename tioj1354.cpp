#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
ll dp[mxn][5];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[0][1] = 1;
    for(int i = 1;i<mxn;i++){
        for(int j = 1;j<=4;j++){
            for(int k = 1;k<=4;k++){
                if(k == j)continue;
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n][1]<<'\n';
    }
    return 0;
}