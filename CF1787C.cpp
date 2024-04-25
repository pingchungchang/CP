#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,s;
	cin>>n>>s;
	ll arr[n+1] = {};
	memset(arr,0,sizeof(arr));
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll dp[n+1][2] = {};//dp[i][0]:x = lim.fs,else:y = lim.fs;
	memset(dp,0,sizeof(dp));
	pll lim[n+1];
	for(int i = 1;i<=n;i++){
		if(arr[i]<=s){
			lim[i].fs = 0,lim[i].sc = arr[i];
		}
		else{
			lim[i].fs = s,lim[i].sc = arr[i]-s;
		}
	}
	dp[2][0] = lim[2].fs*arr[1];
	dp[2][1] = lim[2].sc*arr[1];
	for(int i = 3;i<=n;i++){
		dp[i][0] = min({dp[i-1][0]+lim[i-1].sc*lim[i].fs,dp[i-1][1]+lim[i-1].fs*lim[i].fs});
		dp[i][1] = min({dp[i-1][0]+lim[i-1].sc*lim[i].sc,dp[i-1][1]+lim[i-1].fs*lim[i].sc});
	}
	cout<<min(dp[n-1][0]+lim[n-1].sc*arr[n],dp[n-1][1]+lim[n-1].fs*arr[n])<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
