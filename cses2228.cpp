#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const int mxn =1e6+10;
ll dp[101][101];
ll fac[mxn];

int main(){
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;

    dp[0][0] = 1;
    for(int i = 1;i<=10;i++){
        for(int j = i;j<=10;j++){
            dp[i][j] = (dp[i][j-1]*i+dp[i-1][j-1]*i)%mod;
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[4][6];
}
/*
dp[i][j] = dp[i-1][j]+dp[i-1][j-1]
C(i,j) = C(i-1,j)+C(i-1,j-1)
->C(i-1,j-1) = C(i,j)-C(i-1,j)
f(n,m) = m^n-f(n-1,m)*C(n,1)-f(n-2,m)*C(n,2)-f(n-3,m)*C(n,3)
f(m) = m^n-f(m-1)*C(m,1)-f(m-2)*C(m,2)-f(m-3)*C(m,3)-....-f(1)*C(m,1);
f(m+1) = (m+1)^n-f(m)*C(m,1)-f(m-1)*C(m,2)-f(m-2)*C(m,3)
f(m+1)+F(m) = m^n+(m+1)^n-f(m)*C(m,1)-f(m-1)*C(m+1,2)-f(m-2)*C(m+1,3)-...
*/