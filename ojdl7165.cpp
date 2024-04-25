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

//rewrite!!
const ll mxn = 1<<21;
ll bits = 21;
const ll mod = 1e9+7;
ll dp[mxn],dp2[mxn];
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
ll inverse(ll k){
	return pw(k,mod-2);
}
main(){
//	io
	ll n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>dp[i];
	for(int i = 0;i<bits;i++){
		for(int j = 0;j<mxn;j++){
			if(j&(1<<i))dp[j^(1<<i)]+=dp[j];
			if((j&(1<<i))&&dp[j^(1<<i)]>=mod)dp[j^(1<<i)] -= mod;
		}
	}
	for(int i = 0;i<n;i++)cout<<dp[i]<<',';cout<<endl;
	for(auto &i:dp)i = pw(i,k);
	for(int i = 0;i<mxn;i++)dp2[i] = mod-dp[i];
	for(int i = 0;i<bits;i++){
		for(int j = 0;j<mxn;j++){
			if(j&(1<<i))dp2[j^(1<<i)]+=dp2[j];
			if((j&(1<<i))&&dp2[j^(1<<i)]>=mod)dp2[j^(1<<i)] -= mod;
		}
	}
//	return 0;
	for(int i = 0;i<mxn;i++){
		dp[i] = dp[i]+dp[i]-dp2[i]+mod;
		while(dp[i]>=mod)dp[i] -= mod;
	}
	fill(dp2,dp2+mxn,0LL);
	fill(dp2,dp2+n,1LL);
	for(int i = 0;i<bits;i++){
		for(int j = 0;j<mxn;j++){
			if(j&(1<<i))dp[j^(1<<i)]+=dp[j];
			if((j&(1<<i))&&dp[j^(1<<i)]>=mod)dp[j^(1<<i)] -= mod;
		}
	}
	for(int i = 0;i<n;i++){
		cout<<dp[i]*inverse(dp2[i])%mod<<' ';
	}	
	return 0;
}

