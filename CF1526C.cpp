#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	ll ans = 0;
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,LONG_LONG_MAX));
	for(ll i = 0;i<n;i++)cin>>v[i];
	for(ll i = 0;i<=n;i++)dp[i][0] = 0;
	for(ll i = 1;i<=n;i++){
		for(ll j = i;j>=1;j--){
			dp[i][j] = dp[i-1][j];
			if(dp[i-1][j-1] != LONG_LONG_MAX)dp[i][j] = min(dp[i][j],dp[i-1][j-1]-v[i-1]);
			if(dp[i][j]>0)dp[i][j] = LONG_LONG_MAX;
		}
	}
	for(ll i = n;i>=0;i--){
		if(dp[n][i]<=0){
			cout<<i<<'\n';
			return 0;
		}
	}
}

//dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]-v[i]);
