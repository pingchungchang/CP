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

struct node{
	ll lim;
	
};
void solve(){
	ll n;
	cin>>n;
	vector<vector<ll>> arr(2,vector<ll>(n));
	ll ans = INT_MAX;
	for(ll i = 0;i<2;i++)for(ll j = 0;j<n;j++)cin>>arr[i][j];

	ll ddp = max(arr[0][n-1]+1,arr[1][n-1]+2);
	ll udp = max(arr[1][n-1]+1,arr[0][n-1]+2);
	ll cnt = 2;
	auto dp = arr;
	dp[1][0] = arr[1][0]+1;
	for(ll i = 1;i<n;i++){
		if(i&1){
			dp[1][i] = max(dp[1][i-1],dp[1][i])+1;
			dp[0][i] = max(dp[1][i],dp[0][i])+1;
		}
		else{
			dp[0][i] = max(dp[0][i-1],dp[0][i])+1;
			dp[1][i] = max(dp[0][i],dp[1][i])+1;
		}
	}
//	for(auto i:dp){
//		for(auto j:i)cout<<j<<' ';cout<<'\n';
//	}
	for(ll i = n-2;i>=0;i--){
		if(i&1){
			ans = min(ans,max(dp[0][i]+cnt,udp));
			if(arr[0][i]+cnt+1>=udp)udp = arr[0][i]+cnt+1;
			if(arr[0][i]>=ddp)ddp = arr[0][i]+1;
			else ddp++;
			cnt++;
			ans = min(ans,max(dp[1][i]+cnt,ddp));
			if(arr[1][i]+cnt+1>=ddp)ddp = arr[1][i]+cnt+1;
			if(arr[1][i]>=udp)udp = arr[1][i]+1;
			else udp++;
			cnt++;
		}
		else{
			ans = min(ans,max(dp[1][i]+cnt,ddp));
			if(arr[1][i]+cnt+1>=ddp)ddp = arr[1][i]+cnt+1;
			if(arr[1][i]>=udp)udp = arr[1][i]+1;
			else udp++;
			cnt++;
			ans = min(ans,max(dp[0][i]+cnt,udp));
			if(arr[0][i]+cnt+1>=udp)udp = arr[0][i]+cnt+1;
			if(arr[0][i]>=ddp)ddp = arr[0][i]+1;
			else ddp++;
			cnt++;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

