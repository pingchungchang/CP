#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll
const int inf = 1e9;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int dp[n+1] = {};
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i = n-1;i>=0;i--){
		dp[i] = inf;
		if(i+arr[i]+1>n)dp[i] = dp[i+1]+1;
		else dp[i] = min(dp[i+1]+1,dp[i+arr[i]+1]);
	}
	cout<<dp[0]<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
