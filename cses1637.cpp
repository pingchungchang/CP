#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin>>n;
	vector<ll> dp((ll)1e6+9,-1);
	dp[0] = 0;
	for(ll i =1;i<10;i++)dp[i] = 1;
	for(ll i = 10;i<=n;i++){
		ll k = i;
		dp[i] = LONG_LONG_MAX-2;
		while(k != 0){
			dp[i] = min(dp[i],dp[i-(k%10)]+1);
			k/=10;
		}
	}
	cout<<dp[n];
}
