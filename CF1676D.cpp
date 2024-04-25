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
	ll arr[n][m];
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cin>>arr[i][j];
	vector<vector<pll>> dp(n,vector<pll>(m,make_pair(0,0)));
	for(int i = 0;i<n;i++){
		ll tmp = 0;
		for(int j = 0;j+i<n&&j<m;j++){
			tmp += arr[i+j][j];
		}
		for(int j = 0;j+i<n&&j<m;j++){
			dp[i+j][j].fs = tmp;
		}
	}
	for(int i = 0;i<m;i++){
		ll tmp = 0;
		for(int j = 0;j+i<m&&j<n;j++){
			tmp += arr[j][i+j];
		}
		for(int j= 0;j+i<m&&j<n;j++){
			dp[j][i+j].fs = tmp;
		}
	}
	for(int i = 0;i<n;i++){
		ll tmp = 0;
		for(int j = 0;i-j>=0&&j<m;j++){
			tmp += arr[i-j][j];
		}
		for(int j = 0;i-j>=0&&j<m;j++){
			dp[i-j][j].sc = tmp;
		}
	}
	for(int i = 0;i<m;i++){
		ll tmp = 0;
		for(int j = n-1;j>=0&&i+n-1-j<m;j--){
			tmp += arr[j][i+n-1-j];
		}
		for(int j = n-1;j>=0&&i+n-1-j<m;j--){
			dp[j][i+n-1-j].sc = tmp;
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++)for(ll j = 0;j<m;j++){
		ans = max(ans,dp[i][j].fs+dp[i][j].sc-arr[i][j]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

