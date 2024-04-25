#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,0);
	dp[0] = 1;
	for(ll i =0;i<n;i++){
		ll k;
		cin>>k;
		for(ll j =0;j+k<=x;j++){
			dp[j+k]+= dp[j];
			dp[j+k]%=mod;
		}
	}
	cout<<dp[x];
}
