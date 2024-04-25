#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i = 1;i<n;i++){
		dp[0][i] = dp[0][i-1];
		if(v[0][i] == 'X')dp[0][i] = -1;
		if(dp[0][i] != -1&&v[0][i] != 'B'){
			dp[0][i] += v[0][i]-'0';
		}
	}
	for(int i = 1;i<n;i++){
		dp[i][0] = dp[i-1][0];
		if(v[i][0] == 'X')dp[i][0] = -1;
		if(dp[i][0] != -1)dp[i][0]+= v[i][0]-'0';
		for(int j = 1;j<n;j++){
			if(v[i][j] == 'X'){
				dp[i][j] = -1;
				continue;
			}
			dp[i][j] = -1;
			if(dp[i-1][j] != -1){
				dp[i][j] = dp[i-1][j];
				if(v[i][j] != 'B')dp[i][j]+= v[i][j]-'0';
			}
			if(dp[i][j-1] != -1){
				if(v[i][j] != 'B')dp[i][j] = max(dp[i][j],dp[i][j-1]+v[i][j]-'0');
				else dp[i][j] = max(dp[i][j],dp[i][j-1]);
			}
		}
	}
	if(dp[n-1][n-1] == -1)cout<<'X';
	else cout<<dp[n-1][n-1];
}
