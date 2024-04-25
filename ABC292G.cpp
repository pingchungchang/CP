#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 998244353;

const ll mxn = 44;
ll dp[2][mxn][10];
string arr[mxn];

ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return re;
}
ll mad(ll a,ll b){
    if(b>=mod)b %= mod;
    if(a>=mod)a %= mod;
    a += b;
    if(a>=mod) a-= mod;
    return a;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)cin>>s[i];
    bool roll = 0;
    if(arr[0][m-1] == '?')for(int i = 0;i<10;i++)dp[roll][m-1][i] = 1;
    else dp[roll][m-1][arr[0][m-1]-'0'] = 1;
    for(int i = m-2;i>=0;i--){
        ll total = 0;
        for(int j = 0;j<10;j++)total = mad(total,dp[roll][i+1][j]);
        if(arr[0][i] == '?'){
            for(int j = 0;j<10;j++)dp[roll][i][j] = total;
        }
        else dp[roll][i][arr[i][j]-'0'] = total;
    }
    for(int i = 1;i<n;i++){
        roll ^= 1;
        memset(dp[roll],0LL,sizeof(dp[roll]));
        if(arr[i][m-1] == '?'){
            ll total = dp[roll^1][m-1][0];
            for(int j = 1;j<10;j++){
                dp[roll][m-1][j] = total;
                total = mad(dp[roll^1][m-1][j],total);
            }
        }
        else{
            ll total = 0;
            for(int j = 0;j<arr[i][m-1]-'0';j++){
                dp[roll][m-1][arr[i][m-1]-'0'] += dp[roll^1][m-1][j];
            }
        }
        for(int j = m-2;j>=0;j--){
            if(arr[i][j] == '?'){
                ll ta = dp[roll^1][j][0],tb = 0;
                for(int k = 0;k<10;k++)tb = mad(tb,dp[roll][j+1][k]);
                if(arr[i-1][j] == '?'||arr[i-1][j] == '0')dp[roll][j][0] = tb;
                for(int k = 1;k<10;k++){
                    dp[roll][j][k] = tb*(arr[i-1][j] == '?'||arr[i-1][j]-'0' == k?1:0)+ta;
                    ta = mad(dp[roll^1][j][k],ta);
                }
            }
            else{
                ll ta = 0,tb = 0;
                for(int k = 0;k<arr[i][j]-'0';k++){
                    ta = mad(ta,dp[roll^1][j][k]);
                }
                for(int k = 0;k<10;k++)tb = mad(tb,dp[roll][j+1][k]);
                dp[roll][j][arr[i][j]-'0'] = mad(ta,(arr[i-1][j] == '?'||arr[i-1][j] == arr[i][j]?1LL:0LL)*tb);
            }
        }
    }
    ll total = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<10;j++){
            total = mad(total,dp[roll][i][j]);
        }
    }
    cout<<total;
}