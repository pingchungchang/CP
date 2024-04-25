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
void solve(){
	ll n;
	cin>>n;
	vector<vector<ll>> dp(2,vector<ll>(10000,INT_MAX));
	int now = 0,pre = 1;
	vector<ll> v(n);
	ll ans = INT_MAX;
	for(int i = 0;i<n;i++)cin>>v[i];
	dp[now][v[0]] = 0;
	for(int i = 1;i<n;i++){
		swap(pre,now);
		dp[now] = vector<ll>(10000,INT_MAX);
		for(int j = 0;j<8192;j++){
			dp[now][v[i]^j] = dp[pre][j];
			if(j != 0)dp[now][v[i]^j]++;
		}
		dp[now][v[i]] = min(*min_element(_all(dp[pre]))+1,dp[pre][0]);
	}
	for(int i = 0;i<8192;i++){
		ans = min(ans,dp[now][i]+(i != 0));
	}
	cout<<ans<<'\n';
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

