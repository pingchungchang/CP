#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	ll n,x,y;
	cin>>n>>x>>y;
	ll dp[2][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][1] = 1;
	for(ll i = 2;i<=n;i++){
		dp[0][i] = dp[1][i-1]+y*dp[0][i-1];
		dp[1][i] = x*dp[0][i]+dp[1][i-1];
	}
	cout<<dp[1][n];
}

