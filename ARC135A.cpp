#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
map<ll,ll> dp;
ll f(ll x){
	if(dp.count(x) != 0)return dp[x];
	dp[x] = f(x/2)*f((x+1)/2)%mod;
	return dp[x];
}
int main(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	ll x;
	cin>>x;
	cout<<f(x);		
}
