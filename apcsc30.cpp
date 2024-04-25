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
int main(){
	io
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll dp[n];
	dp[0] = 0;
	for(int i = 1;i<n;i++){
		dp[i] = LONG_LONG_MAX;
		for(int j= i-1;j>=0&&j>=i-k;j--){
			dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
		}
	}
	cout<<dp[n-1];
}

