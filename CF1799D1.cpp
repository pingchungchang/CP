#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;
const ll mxn = 5050;
ll dp[2][mxn];
ll cold[mxn],hot[mxn];
ll arr[mxn];

void solve(){
	ll n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=k;i++)cin>>cold[i];
	for(int i = 1;i<=k;i++)cin>>hot[i];
	bool roll = 0;
	fill(dp[roll],dp[roll]+k+1,inf);
	if(n == 1){
		cout<<cold[arr[1]]<<'\n';
		return;
	}
	dp[roll][0] = cold[arr[1]];
	for(int i = 2;i<=n;i++){
		roll ^= 1;
		fill(dp[roll],dp[roll]+k+1,inf);
		if(arr[i] == arr[i-1]) for(int j = 0;j<=k;j++)dp[roll][j] = dp[roll^1][j]+hot[arr[i]];
		else for(int j = 0;j<=k;j++)dp[roll][j] = dp[roll^1][j]+cold[arr[i]];
		for(int j = 0;j<=k;j++){
			dp[roll][arr[i-1]] = min(dp[roll^1][j]+(arr[i] == j?hot[arr[i]]:cold[arr[i]]),dp[roll][arr[i-1]]);
		}
		//for(int j = 0;j<=k;j++)cout<<(dp[roll][j] == inf?inf:dp[roll][j])<<' ';cout<<'\n';
	}
	cout<<*min_element(dp[roll],dp[roll]+k+1)<<'\n';
	//cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
