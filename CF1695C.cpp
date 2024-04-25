#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++){
		cin>>dp[i][j];
		dp2[i][j] = dp[i][j];
	}
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			if(i == 1){
				dp[i][j] += dp[i][j-1];
				dp2[i][j] += dp2[i][j-1];
			}
			else if(j == 1){
				dp[i][j] += dp[i-1][j];
				dp2[i][j] += dp2[i-1][j];
			}
			else{
				dp[i][j] = min(dp[i][j-1],dp[i-1][j])+dp[i][j];
				dp2[i][j] = max(dp2[i][j-1],dp2[i-1][j])+dp2[i][j];
			}
		}
	}
//	cout<<dp[n][m]<<' '<<dp2[n][m]<<'\n';
	if((n+m)%2==0||dp[n][m]>0||dp2[n][m]<0){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

