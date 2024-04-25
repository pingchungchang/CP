#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll k = 1e6+10;
vector<ll> dp(k,0);
int main(){
	ll n;
	cin>>n;
	for(ll i =1;i<=6;i++)dp[i] = 1;
	for(ll i =1;i<n;i++){
		for(ll j =1;j<=6;j++){
			dp[i+j]+= dp[i];
			dp[i+j] = dp[i+j]%mod;
		}
	}
	cout<<dp[n];
}
