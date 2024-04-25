#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
int main(){
	ll n;
	cin>>n;
	if(n%4!=0&&n%4!=3){
		cout<<0;
		return 0;
	}
	vector<ll> dp(n*(n+1)/2+1,0);
	dp[0] = 1;
	for(ll i =1;i<n;i++){
		for(ll j = n*(n+1)/2;j>=i;j--){
			dp[j] = dp[j]+dp[j-i];
			dp[j]%=mod;
		}
	}
	cout<<dp[n*(n+1)/4-n];
}
