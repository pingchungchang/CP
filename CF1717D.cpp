#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
const ll mxn = 1e5+10;
ll fac[mxn];
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
	ll a,b;
	ll n,k;
	cin>>n>>k;
	ll ans = 0;
	for(int i = 0;i<=min(k,n);i++){
		ans += C(n,i);
		if(ans>=mod)ans -= mod;
	}
	cout<<ans;
	return;
}

int main(){
	fac[0] = fac[1] =1 ;
	for(ll i =2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
