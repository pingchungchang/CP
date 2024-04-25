#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mxn = 1010;
const ll inf = 1e18;
ll sum[mxn][mxn];
ll dp[mxn][mxn];
ll a[mxn+1],b[mxn+1];
int main(){
    ll n,m;
    cin>>n>>m;
    memset(dp,inf,sizeof(dp));
    for(auto &i:dp)for(auto &j:i)j = inf;
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=m;i++)cin>>b[i];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
        	if(i == 0&&j == 0)continue;
        	else if(i == 0)sum[i][j] = sum[i][j-1]+b[j];
        	else if(j == 0)sum[i][j] = sum[i-1][j]+a[i];
            if(i != 0&&j != 0)sum[i][j] = sum[i-1][j-1]+a[i]+b[j];
        }
    }
    dp[0][0] = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(sum[i][j]<0)continue;
            if(i != 0&&sum[i-1][j]>=0)dp[i][j] = min(dp[i][j],dp[i-1][j]);
            if(j != 0&&sum[i][j-1]>=0)dp[i][j] = min(dp[i][j],dp[i][j-1]);
            dp[i][j] = max(dp[i][j],sum[i][j]);
        }
    }
    cout<<(dp[n][m] == inf?-1:dp[n][m]);
}

