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


const int mxn = 1e3+10;
ll dp[mxn][mxn];
ll arr[mxn];
int n;
void dfs(int l,int r){
	if(dp[l][r] != -1)return;
	dp[l][r] = LONG_LONG_MAX;
	for(int i = l+1;i<r;i++){
		if(dp[l][i] == -1)dfs(l,i);
		if(dp[i][r] == -1)dfs(i,r);
		dp[l][r] = min(dp[l][r],dp[l][i]+dp[i][r]+arr[l]*arr[i]*arr[r]);
	}
	return;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i = 0;i<=n;i++){
		dp[i][i] = 0;
		cin>>arr[i];
	}
	for(int i = 0;i<n;i++){
		dp[i][i+1] = 0;
	}
	dfs(0,n);
	cout<<dp[0][n];
}

