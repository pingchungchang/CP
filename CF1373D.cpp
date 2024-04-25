#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
ll suf[mxn];
ll dp[3][mxn];
ll n;
ll arr[mxn];

void solve(){
	fill(dp[0],dp[0]+n+1,0);
	fill(dp[1],dp[1]+n+1,0);
	fill(dp[2],dp[2]+n+1,0);
	fill(suf,suf+n+1,0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = n-1;i>=0;i--){
		if(!(i&1))suf[i] = suf[i+2]+arr[i];
		else suf[i] = suf[i+1];
	}
	ll ans = 0;
	for(int i = 0;i<n;i+=2)ans += arr[i];
	dp[0][0] = arr[0];//haven't started
	dp[1][0] = 0;//start with odd
	dp[2][0] = 0;//start with even
	for(int i = 1;i<n;i++){
		if(i&1){
			dp[0][i] = dp[0][i-1];
			dp[1][i] = max(dp[0][i-1],dp[1][i-1])+arr[i];
			dp[2][i] = dp[2][i-1]+arr[i];
			ans = max({ans,dp[2][i]+suf[i+1]});
		}
		else{
			dp[0][i] = dp[0][i-1]+arr[i];
			dp[1][i] = dp[1][i-1];
			dp[2][i] = max(dp[0][i-1],dp[2][i-1]);
			ans = max({ans,dp[1][i]+suf[i+2]});
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
