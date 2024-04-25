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
	io
	ll n,m;
	cin>>n>>m;
	ll dp[n+1][n+1];
	memset(dp,0LL,sizeof(dp));
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll vals[n+1];
	memset(vals,0LL,sizeof(vals));
	for(int i = 0;i<m;i++){
		ll k,x;
		cin>>k>>x;
		vals[k] += x;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			dp[i][0] = max(dp[i-1][j]+vals[0],dp[i][0]);
			dp[i][j] = dp[i-1][j-1]+arr[i]+vals[j];
		}
	}
	ll ans = 0;
	for(int i = 0;i<=n;i++)ans = max(ans,dp[n][i]);
	cout<<ans;
}

