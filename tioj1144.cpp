#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

unordered_map<ll,ll> dp[2];
const ll mxn = 220;
const ll mxn2 = mxn*mxn;
const ll mxn3 = mxn2*mxn;
ll dist[mxn][mxn];

ll h(int arr[]){
    return mxn2*arr[0]+mxn*arr[1]+arr[2];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)cin>>dist[i][j];
    }
    int k;
    short roll = 0;
    dp[roll][mxn2+2*mxn+3] = 0;
    while(cin>>k){
        roll ^= 1;
        dp[roll].clear();
        for(auto &i:dp[roll^1]){
            int now[] = {i.first/mxn2,i.first%mxn2/mxn,i.first%mxn2%mxn};
            // cout<<now[0]<<' '<<now[1]<<' '<<now[2]<<'\n';
            ll val = i.second;
            int now1[] = {now[0],now[1],k};
            ll val1 = val+dist[now[2]][k];
            sort(now1,now1+3);
            if(dp[roll].find(h(now1)) == dp[roll].end())dp[roll][h(now1)] = val1;
            else dp[roll][h(now1)] = min(dp[roll][h(now1)],val1);
            int now2[] = {now[0],k,now[2]};
            val1 = val+dist[now[1]][k];
            sort(now2,now2+3);
            if(dp[roll].find(h(now2)) == dp[roll].end())dp[roll][h(now2)] = val1;
            else dp[roll][h(now2)] = min(dp[roll][h(now2)],val1);
            int now3[] = {k,now[1],now[2]};
            val1 = val+dist[now[0]][k];
            sort(now3,now3+3);
            if(dp[roll].find(h(now3)) == dp[roll].end())dp[roll][h(now3)] = val1;
            else dp[roll][h(now3)] = min(dp[roll][h(now3)],val1);
        }
    }
    ll ans= 1e18;
    for(auto &i:dp[roll])ans = min(ans,i.second);
    cout<<ans;
}