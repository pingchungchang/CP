#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

#define ll long long
const ll mod = 998244353;
const ll mxn = 5e5+10;
ll fac[mxn],ifac[mxn],dp[mxn];

inline pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll C(ll a,ll b){
	if(b>a)return 1;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}


void solve(){
	ll n;
	cin>>n;
	n--;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll dp[n+1][4];
	memset(dp,0,sizeof(dp));
	if(!arr[1])dp[1][0] = dp[1][1] = 1;
	else dp[1][2] = 0,dp[1][3] = 1;
	ll ans[n+1];
	for(ll i = 2;i<=n;i++){
		if(!arr[i]){
			dp[i][0] = mad(dp[i-1][0]*i%mod,dp[i-1][1]);
			dp[i][1] = dp[i-1][1]*i%mod;
			dp[i][2] = dp[i-1][2]*i%mod;
			dp[i][3] = dp[i-1][3]*i%mod;
		}
		else{
			dp[i][0] = dp[i-1][0]*(i-1)%mod;
			dp[i][1] = dp[i-1][1]*(i-1)%mod;
			dp[i][2] = mad(dp[i-1][2]*i%mod,dp[i-1][0]);
			dp[i][3] = mad(dp[i-1][3]*i%mod,dp[i-1][1]);
		}
	}
	for(int i = 1;i<=n;i++)cout<<mad(dp[i][0],dp[i][2])<<' ';cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
		ifac[i] = inv(fac[i]);
	}
	int t;cin>>t;
	while(t--)solve();
}
