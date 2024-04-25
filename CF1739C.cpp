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
const ll mod = 998244353;
ll dp[2][66],fac[66];
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}
ll C(ll a,ll b){
	return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
void solve(){
	ll n;
	cin>>n;
//	cout<<dp[(n/2+1)&1][n]<<' '<<(C(n,n/2)-1-dp[(n/2+1)&1][n]+mod+mod)%mod<<' '<<1<<'\n';
	cout<<dp[0][n]<<' '<<dp[1][n]<<' '<<1<<'\n';
	return;
}
int main(){
	io
	fac[0] = fac[1] = 1;
	for(int i = 2;i<=60;i++)fac[i] = fac[i-1]*i%mod;
	dp[0][2] = 1;
	for(ll i = 4;i<=60;i+=2){
		dp[0][i] = dp[1][i-2]+C(i-1,i/2);
		dp[1][i] = dp[0][i-2]+C(i-2,i/2);
		dp[0][i]%=mod;
		dp[1][i]%=mod;
	}
	int t;
	cin>>t;
	while(t--)solve();
}

