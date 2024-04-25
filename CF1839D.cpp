#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define DEBUG(x) cout<<#x<<":"<<x<<endl;
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 505;
int dp[2][mxn][mxn][2];

void solve(){
	int n;
	cin>>n;
	int arr[n];
	bool roll = false;
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<=1;i++)for(int j = 0;j<=n;j++)for(int k = 0;k<=n;k++)dp[i][j][k][0] = dp[i][j][k][1] = mxn*mxn;
	dp[0][0][arr[0]][0] = 0;
	dp[0][1][0][1] = 1;
	for(int i = 1;i<n;i++){
		roll ^= 1;
		for(int j = 0;j<=n;j++)for(int k = 0;k<=n;k++)dp[roll][j][k][0] = dp[roll][j][k][1] = mxn*mxn;
		for(int j = 1;j<=n;j++){
			for(int k = 0;k<=n;k++){
				dp[roll][j][k][1] = min(dp[roll^1][j-1][k][0],dp[roll^1][j][k][1])+1;
			}
		}
		for(int j = 0;j<=n;j++){
			for(int k = 0;k<=arr[i];k++){
				dp[roll][j][arr[i]][0] = min({dp[roll][j][arr[i]][0],dp[roll^1][j][k][0],dp[roll^1][j][k][1]});
			}
		}
		//for(int j = 0;j<=n;j++)for(int k = 0;k<=n;k++)dp[i][j][k][0] = min(dp[i][j][k][0],dp[i][j][k][1]);
	}
	/*
	for(int i = 0;i<n;i++)for(int j= 0;j<=n;j++)for(int k = 0;k<=n;k++){
		cout<<i<<','<<j<<','<<k<<":"<<dp[i][j][k][0]<<','<<dp[i][j][k][1]<<endl;
	}

   */
	int ans = mxn*mxn;
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			ans = min({ans,dp[roll][i][j][0],dp[roll][i][j][1]});
		}
		if(i)cout<<ans<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
