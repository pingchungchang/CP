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
	int n;
	ll k;
	cin>>n>>k;
	ll dp[n][34];
	memset(dp,0LL,sizeof(dp));
	ll v[n][34];
	memset(v,0LL,sizeof(v));
	for(int i = 0;i<n;i++)cin>>v[i][0];
	for(int i = 0;i<n;i++){
		for(int j = 1;j<34;j++)v[i][j] = v[i][j-1]/2;
	}
	for(int i = 0;i<n;i++){
		dp[i][0] = v[i][0]-k;
		if(i != 0)dp[i][0] += dp[i-1][0];
	}
	for(int i = 1;i<34;i++)dp[0][i] = v[0][i];
	for(int i = 1;i<n;i++){
		for(int j = 1;j<34;j++){
			dp[i][j] = max(dp[i-1][j]+v[i][j]-k,dp[i-1][j-1]+v[i][j]);
		}
		dp[i][33] = max(dp[i][33],dp[i-1][33]);
	}
	ll ans = INT_MIN;
//	for(int i = 0;i<34;i++)ans = max(ans,dp[n-1][i]);
	cout<<*max_element(dp[n-1],dp[n-1]+34)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

