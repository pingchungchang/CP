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
const int mxn = 505;
int n;
ll dp[mxn][mxn];
ll arr[mxn];
ll pref[mxn];
void dfs(int l,int r){
//	cout<<l<<' '<<r<<endl;
	if(dp[l][r] != -1)return;
	dp[l][r] = LONG_LONG_MAX;
	for(int i = l;i<r;i++){
		if(dp[l][i] == -1)dfs(l,i);
		if(dp[i+1][r] == -1)dfs(i+1,r);
		dp[l][r] = min(dp[l][r],dp[l][i]+dp[i+1][r]+pref[r]-pref[l-1]);
	}
	return;
}
int main(){
	io
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	for(int i = 0;i<=n;i++)dp[i][i] = 0;
	dfs(1,n);
	cout<<dp[1][n];
}

