#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int v[n][m];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++)cin>>v[i][j];
	}
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m));
	dp[0][0].first = v[0][0];
	dp[0][m-1].second = v[0][m-1];
	for(int i =1;i<m;i++){
		dp[0][i].first = v[0][i]+max(0,dp[0][i-1].first);
		dp[0][m-1-i].second = v[0][m-1-i]+max(0,dp[0][m-i].second);
	}
	for(int i =1;i<n;i++){
		dp[i][0].first = max(dp[i-1][0].first,dp[i-1][0].second)+v[i][0];
		dp[i][m-1].second = max(dp[i-1][m-1].second,dp[i-1][m-1].first)+v[i][m-1];
		for(int j =1;j<m;j++){
			dp[i][j].first = v[i][j]+ max(dp[i][j-1].first,max(dp[i-1][j].first,dp[i-1][j].second));
			dp[i][m-1-j].second = v[i][m-1-j]+max(dp[i][m-j].second,max(dp[i-1][m-1-j].first,dp[i-1][m-1-j].second));
		}
	}
	int ans=INT_MIN;
	for(int i =0;i<m;i++){
		ans = max(ans,max(dp[n-1][i].first,dp[n-1][i].second));
	}
	cout<<ans;
}
