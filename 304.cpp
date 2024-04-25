#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 150005;
ll dp[2][mxn];
ll a[mxn],b[mxn],t[mxn];
#define pll pair<ll,ll>
#define fs first
#define sc second

pll dq[mxn];
int pl,pr;

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
    for(int i = 1;i<m;i++){
        roll ^= 1;
        pl = pr = 0;
        ll dist = d*(t[i]-t[i-1]);
        for(int j = 1;j<=n;j++){
            while(pl != pr&&dq[pl].sc<j-dist)pl++;
            while(pl != pr&&dq[pr-1].fs<dp[roll^1][j])pr--;
            dq[pr] = {dp[roll^1][j],j};
            pr++;
            dp[roll][j] = dq[pl].fs+b[i]-abs(a[i]-j);
        }
        // cout<<pl<<' '<<pr<<endl;
        pl = pr = 0;
        for(int j= n;j>=1;j--){
            while(pl != pr&&dq[pl].sc>j+dist)pl++;
            while(pl != pr&&dq[pr-1].fs<dp[roll^1][j])pr--;
            dq[pr] = {dp[roll^1][j],j};
            pr++;
            dp[roll][j] = max(dq[pl].fs+b[i]-abs(a[i]-j),dp[roll][j]);
        }
        // cout<<pl<<' '<<pr<<endl;
        // for(int j= 1;j<=n;j++)cout<<dp[roll][j]<<' ';cout<<endl;
    }
    cout<<*max_element(dp[roll]+1,dp[roll]+n+1);
}
/*

*/