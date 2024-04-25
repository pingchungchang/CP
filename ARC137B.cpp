#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int dp[2][n];
	memset(dp,0,sizeof(dp));
	int pre[n] = {};
	if(arr[0] == 1)pre[0] = 1;
	for(int i = 1;i<n;i++)pre[i] = pre[i-1]+arr[i];
	if(arr[0] == 0)dp[0][0] = 1;
	dp[1][0] = dp[0][0];
	for(int i = 1;i<n;i++){
		dp[0][i] = (1-arr[i])+max(pre[i-1],dp[0][i-1]);
		dp[1][i] = max(dp[1][i-1]+arr[i],dp[0][i]);
	}
	int b = dp[1][n-1];
	for(int i = 0;i<2;i++){
		for(int j = 0;j<n;j++)cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	memset(dp,0,sizeof(dp));
	
	if(arr[0] == 0)dp[0][0] = 1;
	for(int i = 1;i<n;i++){
		dp[0][i] = (1-arr[i])+min(pre[i-1],dp[0][i-1]);
		dp[1][i] = min(dp[1][i-1]+arr[i],dp[0][i]);
	}
	for(int i = 0;i<2;i++){
		for(int j = 0;j<n;j++)cout<<dp[i][j]<<' ';
		cout<<endl;
	}	
	int s = dp[1][n-1];;
	cout<<b-s+1<<'\n';
	return 0;
}

