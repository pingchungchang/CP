#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n+1];
	for(int i= 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	reverse(arr+1,arr+n+1);
	ll dp[n+1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=n;i++){
		ll cnt = (x+arr[i]-1)/arr[i];
		dp[i] = dp[i-1];
		if(i-cnt>=0)dp[i] = max(dp[i],dp[i-cnt]+1);
	}
	cout<<dp[n]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
