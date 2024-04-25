#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 1010;
ll dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	dp[1] = 1;
	for(ll i = 2;i<mxn;i++){
		dp[i] = dp[i-1]*i%mod*i%mod;
	}
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		if(k&1)cout<<0<<'\n';
		else cout<<dp[k/2]<<'\n';
	}
}
