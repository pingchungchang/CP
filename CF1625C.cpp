#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
vector<vector<int>> dp;
vector<int> sign;
vector<int> v;
void f(int now,int t){
	if(dp[now][t] != INT_MAX)return;
	if(now<=t){
		dp[now][t] = INT_MAX;
		return;
	}
	if(dp[3][2] == 0)cout<<now<<' '<<t<<endl;
	for(int i = 0;i<=t;i++){
		f(now-i-1,t-i);
		if(dp[now-i-1][t-i] != INT_MAX){
			dp[now][t] = min(dp[now][t],dp[now-i-1][t-i]+sign[now-i]*(v[now]-v[now-i-1]));
		}
	}
	return;
}
main(){
	io
	int n,l,k;
	cin>>n>>l>>k;
	sign = vector<int>(n+1,0);
	v = vector<int> (n+1);
	for(int i = 0;i<n;i++)cin>>v[i];
	v.back() = l;
	for(int i = 1;i<=n;i++)cin>>sign[i];
	dp = vector<vector<int>>(n+1,vector<int>(k+1,INT_MAX));
	dp[0][0] = 0;
	for(int i = 1;i<=n;i++){
		dp[i][0] = dp[i-1][0]+sign[i]*(v[i]-v[i-1]);
	}
	int ans = INT_MAX;
	for(int i = 0;i<=k;i++){
		if(dp[n][i] == INT_MAX)f(n,i);
		ans = min(ans,dp[n][i]);
	}
//	for(int j = 0;j<=k;j++){
//		for(int i = 0;i<=n;i++)
//		cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	cout<<ans;
}

