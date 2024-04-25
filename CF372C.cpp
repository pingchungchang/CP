#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")

#define ll long long
const int mxn = 150005;
ll dp[2][mxn];
ll a[mxn],b[mxn],t[mxn];
#define pll pair<ll,ll>
#define fs first
#define sc second

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    for(int i = 0;i<m;i++){
        cin>>a[i]>>b[i]>>t[i];
    }
    short roll = 0;
    for(int i = 1;i<=n;i++){
        dp[roll][i] = b[0]-abs(a[0]-i);
    }
    deque<pll> dq;
    for(int i = 1;i<m;i++){
        roll ^= 1;
        ll dist = d*(t[i]-t[i-1]);
        while(!dq.empty())dq.pop_back();
        for(int j = 1;j<=n;j++){
            while(!dq.empty()&&dq.front().sc<j-dist)dq.pop_front();
            while(!dq.empty()&&dq.back().fs<dp[roll^1][j])dq.pop_back();
            dq.push_back({dp[roll^1][j],j});
            dp[roll][j] = dq.front().fs+b[i]-abs(a[i]-j);
        }
        while(!dq.empty())dq.pop_back();
        for(int j= n;j>=1;j--){
            while(!dq.empty()&&dq.front().sc>j+dist)dq.pop_front();
            while(!dq.empty()&&dq.back().fs<dp[roll^1][j])dq.pop_back();
            dq.push_back({dp[roll^1][j],j});
            dp[roll][j] = max(dp[roll][j],dq.front().fs+b[i]-abs(a[i]-j));
        }
    }
    cout<<*max_element(dp[roll]+1,dp[roll]+n+1);
}