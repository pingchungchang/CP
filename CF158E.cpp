#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	int dp[k+1];
	fill(dp,dp+k+1,1);
	int ans = 0;
	for(auto &now:arr){
		for(int i = k;i>=1;i--){
			ans = max(ans,now.fs-dp[i]);
			dp[i] = min(max(dp[i],now.fs)+now.sc,dp[i-1]);
		}
		ans = max(ans,now.fs-dp[0]);
		dp[0] = max(dp[0],now.fs)+now.sc;
	}
	ans = max(ans,86401-dp[k]);
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
