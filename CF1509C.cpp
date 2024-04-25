#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2020;
ll dp[mxn][mxn];

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	for(int i = 0;i<=n;i++)for(int j = 0;j<=n;j++)dp[i][j] = 1e18;
	for(int i = 0;i<n;i++)dp[i][i] = 0;
	for(int i = 1;i<n;i++){
		for(int j = 0;j<n-i;j++){
			dp[j][i+j] = min(dp[j+1][i+j],dp[j][i+j-1])+arr[i+j]-arr[j];
		}
	}
	cout<<dp[0][n-1];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
