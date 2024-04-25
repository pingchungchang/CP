#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+9;

void solve(){
	ll n;
	cin>>n;
	ll dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i<=n;i++){
		dp[i] = dp[i-1]*4-dp[i-2];
		if(dp[i]<mod)dp[i] += mod;
		dp[i] %= mod;
	}
	cout<<dp[n]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
