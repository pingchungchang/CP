#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#define ll long long
const ll mod = 998244353;
ll mad(ll a,ll b){
    a += b;
    if(a>=mod) a -= mod;
    return a;
}
const ll mxn = 110;
ll dp[2][mxn][mxn][mxn];//dp[i][j][k] choose i,now have j,modulo k
bool roll = 0;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<=n;i++)dp[roll][i][0][0] = dp[roll^1][i][0][0] = 1;
    for(auto &x:arr){
        roll ^= 1;
        for(int i = 1;i<=n;i++){
            int m = x%i;
            for(int j = 1;j<=i;j++){
                for(int k = 0;k<i;k++){
                    dp[roll][i][j][k] = mad(dp[roll^1][i][j][k],dp[roll^1][i][j-1][(m>k?k+i-m:k-m)]);
                }
            }
        }
    }
    // for(int i = 0;i<=n;i++){
    //     for(int j = 0;j<=i;j++){
    //         for(int k = 0;k<i;k++){
    //             cout<<i<<' '<<j<<' '<<k<<' '<<dp[roll][i][j][k]<<endl;
    //         }
    //     }
    // }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans = mad(ans,dp[roll][i][i][0]);
    }
    cout<<ans;
}