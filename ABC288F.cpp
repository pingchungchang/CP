#include <bits/stdc++.h>
using namespace std;

#define de(x) cout<<#x<<":"<<x<<'\n';
#define ll long long
const ll mod = 998244353;
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
const ll mxn = 2e5+10;
ll P[mxn],Q[mxn],R[mxn];
ll n;
string s;
ll dp[mxn];
ll ans = 0;
ll inv10 = inv(10);
ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

int main(){
	cin>>n>>s;
	dp[0] = s[0]-'0';
	P[0] = (s[0]-'0');
	Q[0] = dp[0];
	R[0] = P[0]*dp[0]%mod;
	ll psum = s[0]-'0';

/*
	for(ll i = 1;i<n;i++){
		for(ll k = 0;k<i;k++){
			ll total1 = 0;
			for(ll j = k+1;j<=i;j++){
				total1 = mad(total1,pw(10,i-j)*(s[j]-'0')%mod);
			}
			dp[i] = mad(dp[i],dp[k]*total1%mod);
		}
		psum = mad(psum*10%mod,s[i]-'0');
		dp[i] = mad(dp[i],psum);
	}
	for(int i = 0;i<n;i++)de(dp[i]);return 0;
*/

	for(ll i = 1;i<n;i++){
		P[i] = mad(P[i-1],pw(inv10,i)*(s[i]-'0')%mod);
		dp[i] = pw(10,i)*P[i]%mod*Q[i-1]%mod+mod-pw(10,i)*R[i-1]%mod;
		dp[i]%= mod;
		psum = mad(psum*10%mod,s[i]-'0');
		dp[i] = mad(dp[i],psum);
		Q[i] = mad(Q[i-1],dp[i]);
		R[i] = mad(R[i-1],P[i]*dp[i]%mod);
		//cout<<i<<":"<<dp[i]<<endl;
		//de(P[i]*pw(10,i)%mod);de(Q[i]*pw(10,i)%mod);de(R[i]*pw(10,i)%mod);
	}
	cout<<dp[n-1];
}
