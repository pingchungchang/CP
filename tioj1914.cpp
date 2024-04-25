#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<vector<int>> dp(n,vector<int>(n,401));
	for(int i  = 0;i<n;i++)dp[i][i] = 1;
	for(int i = n-1;i>=0;i--){
		for(int j = i+1;j<n;j++){
			if(v[j] == v[j-1]||v[i] == v[j])dp[i][j] = dp[i][j-1];
			for(int k = i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[0][n-1]<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
