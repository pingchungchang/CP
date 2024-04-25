#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;

void solve(){
	int n;
	cin>>n;
	int arr[n] = {};
	int dp[n] = {};
	int cnt[n+1] = {};
	fill(cnt,cnt+n+1,-mxn*2);
	for(int i = 0;i<n;i++)cin>>arr[i];
	dp[0] = 0;
	cnt[arr[0]] = 1;
	int ans = 0;
	for(int i = 1;i<n;i++){
		dp[i] = max(dp[i-1],i+cnt[arr[i]]);
		ans = max(ans,dp[i]);
		cnt[arr[i]] = max(cnt[arr[i]],dp[i-1]-i+1);
		//cout<<i<<":";for(int j = 1;j<=n;j++)cout<<cnt[j]<<' ';cout<<'\n';
	}
	//for(auto &i:dp)cout<<i<<' ';cout<<":";
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
