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
const int mxn = 3030;
ll dp[mxn][mxn];
int main(){
	io
	ll n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)cin>>dp[i][j];
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			dp[i][j] = max({dp[i][j],dp[i-1][j]+dp[i][j],dp[i][j-1]+dp[i][j]});
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans;
}

