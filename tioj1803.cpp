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
#pragma GCC optimize("O2")
const ll mod = 1e9+7;
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
ll mult(vector<ll> v){
	ll re = 1;
	for(auto &i:v)re = re*i%mod;
	return re;
}
const ll mxn = 1e6+10;
ll fac[mxn];
int main(){
	io
	fac[0] = fac[1] = 1;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ll n,k;
	while(cin>>n>>k){
		ll G = __gcd(n,k);
		ll ans = 0;
		for(ll i = 1;i*i<=G;i++){
			if(G%i!= 0)continue;
			ll tmp = n/i;
			if(i != 1){
				ans += fac[n]*inv(fac[n/i])%mod*inv(pw(i,n/i))%mod;
				if(ans>=mod)ans -= mod;
			}
			ll tt = G/i;
			if(tt != i&&tt != 1){
				ans += fac[n]*inv(fac[n/tt])%mod*inv(pw(tt,n/tt))%mod;
				if(ans>=mod)ans -= mod;
			}
//				cout<<i<<' '<<ans<<'\n';
		}
		cout<<ans<<'\n';
	}
}

