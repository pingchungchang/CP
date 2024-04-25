#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<ll> dp(n,0LL);
	for(ll i = 1;i<n-1;i++){
		if(i>2)dp[i] = dp[i-2];
		if(v[i]<=max(v[i+1],v[i-1]))dp[i] += max(v[i+1],v[i-1])-v[i]+1;
	}
	if(n%2 == 1){
		cout<<dp[n-2]<<'\n';
		return;
	}
	ll ans = min(dp[n-2],dp[n-3]);
	for(int i = 1;i<n-1;i+=2){
		ans = min(ans,dp[i]+dp[n-2]-dp[i+1]);
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

