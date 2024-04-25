#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
const ll n = 1e6+1;
ll dp[n][2] = {{0}};
int main(){
	ll t;
	cin>>t;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(ll i =2;i<n;i++){
		dp[i][0] = dp[i-1][0]*4+dp[i-1][1];
		dp[i][0]%= mod;
		dp[i][1] = dp[i-1][0]+2*dp[i-1][1];
		dp[i][1]%= mod;
	}
	
	for(ll i =0;i<t;i++){
		ll k;
		cin>>k;
		cout<<(dp[k][1]+dp[k][0])%mod<<'\n';
	}
}
