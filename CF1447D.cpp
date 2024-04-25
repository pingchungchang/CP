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
int main(){
	io
	int n,m;
	cin>>n>>m;
	int dp[n][m];
	string a,b;
	cin>>a>>b;
	if(a[0] == b[0])dp[0][0] = 2;
	else dp[0][0] = 0;
	for(int i = 1;i<n;i++){
		if(a[i] == b[0])dp[i][0] = 2;
		else{
			dp[i][0] = max(0,dp[i-1][0]-1);
		}
	}
	for(int i = 1;i<m;i++){
		if(a[0] == b[i])dp[0][i] = 2;
		else{
			dp[0][i] = max(0,dp[0][i-1]-1);
		}
	}
	for(int i = 1;i<n;i++){
		for(int j = 1;j<m;j++){
			dp[i][j] = max({dp[i-1][j]-1,dp[i][j-1]-1,0});
			if(a[i] == b[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2);
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)ans = max(ans,dp[i][j]);
	cout<<ans;
}

