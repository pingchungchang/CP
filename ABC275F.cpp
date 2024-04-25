#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define pll pair<ll,ll>

const ll inf = 1e9+10;
const ll mxn = 3010;
ll dp[2][mxn][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    short now = 0,pre = 1;
    cin>>n>>m;
    ll arr[n+1];
    for(int i= 1;i<=n;i++)cin>>arr[i];
    for(auto &i:dp[now])for(auto &j:i)j = inf;
    dp[now][0][0] = 0;dp[now][0][1] = 0;
    for(int i = 1;i<=n;i++){
        swap(now,pre);
        for(auto &a:dp[now])for(auto &j:a)j = inf;
        dp[now][0][0] = 1;dp[now][0][1] = inf;
        for(int j = 1;j<=m;j++){
            if(j<arr[i]){
                dp[now][j][0] = min(dp[pre][j][0],dp[pre][j][1]+1);
                dp[now][j][1] = inf;
            }
            else{
                dp[now][j][0] = min(dp[pre][j][0],dp[pre][j][1]+1);
                dp[now][j][1] = min(dp[pre][j-arr[i]][0],dp[pre][j-arr[i]][1]);
            }
        }
    }
    for(int i = 1;i<=m;i++){
        ll re = min(dp[now][i][0],dp[now][i][1]);
        if(re>=inf)cout<<"-1\n";
        else cout<<re<<'\n';
    }
    return 0;
}
/*
4 5
1 2 3 4

*/
