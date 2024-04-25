#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;
const ll mxn = 1e6+10;
ll fac[mxn];
ll dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	fac[0] = fac[1] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	dp[0] = dp[1] = dp[2] = 0;
	for(int i = 3;i<mxn;i++){
		dp[i] = fac[i-1]*(i-2)+dp[i-1]*2;
		dp[i] %= mod;
	}
	cout<<dp[n];
}
