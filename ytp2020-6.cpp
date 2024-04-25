#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<string>> dp(n,vector<string>(m));
	for(int i = 0;i<n;i++){
		string in;
		cin>>in;
		for(int j = 0;j<m;j++)dp[i][j] = string(1,in[j]);
	}
	for(int i = 1;i<m;i++)dp[0][i] = dp[0][i-1]+dp[0][i];
	for(int i = 1;i<n;i++)dp[i][0] = dp[i-1][0]+dp[i][0];
	for(int i = 1;i<n;i++){
		for(int j = 1;j<m;j++){
			dp[i][j] = min(dp[i-1][j]+dp[i][j],dp[i][j-1]+dp[i][j]);
		}
	}
	cout<<dp[n-1][m-1];
}

