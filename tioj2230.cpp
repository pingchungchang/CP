#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxn = 1e5+10;
ll wt[mxn],bk[mxn],t[mxn];
ll dp[mxn][2];
ll nxt[mxn][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>bk[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>wt[i];
    }
    for(int i = 1;i<=n;i++)cin>>t[i];
    dp[1][0] = bk[1];dp[1][1] = wt[1];
    nxt[1][0] = dp[1][1]+t[1];nxt[1][1] = dp[1][0]+t[1];
    dp[1][0] = min(dp[1][0],nxt[1][0]);
    dp[1][1] = min(dp[1][1],nxt[1][1]);
    for(int i = 2;i<=n;i++){
        dp[i][0] = min(dp[i-1][0]+bk[i],nxt[i-1][0]+bk[i]);
        dp[i][1] = min(dp[i-1][1]+wt[i],nxt[i-1][1]+wt[i]);
        nxt[i][0] = max(nxt[i-1][0],dp[i][1]+t[i]);
        nxt[i][1] = max(nxt[i-1][1],dp[i][0]+t[i]);
        cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<nxt[i][0]<<' '<<nxt[i][1]<<endl;
    }
    cout<<min(dp[n][0],dp[n][1]);
}