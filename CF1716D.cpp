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
#pragma GCC optimize("O3")
const ll mod = 998244353;
int main(){
	ll n,k;
	cin>>n>>k;
	vector<vector<ll>> dp(2,vector<ll>(n+1,0LL));
	ll pre = 1,now = 0;
	dp[now][0] = 1LL;
	vector<ll> ans(n+1,0LL);
	for(ll i = k;(k+i)*(i-k+1)<=n*2;i++){
		swap(now,pre);
		dp[now] = vector<ll>(n+1,0LL);
		for(ll j = 0;j+i<=n;j++){
			dp[now][j+i] += dp[pre][j];
			if(dp[now][j+i]>=mod)dp[now][j+i] -= mod;
		}
		for(ll j = 0;j<=n;j++){
			if(j>=i)dp[now][j] += dp[now][j-i];
			if(dp[now][j]>=mod)dp[now][j] -= mod;
		}
		for(ll j = 1;j<=n;j++){
			ans[j] += dp[now][j];
			if(ans[j]>=mod)ans[j] -= mod;
		}
	}
	for(ll i = 1;i<=n;i++)cout<<ans[i]%mod<<' ';
	
}

