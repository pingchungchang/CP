#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e5+10;
const ll mod = 998244353;
ll fac[mxn],ifac[mxn];

inline ll pw(ll a,ll b){
	if(b<0)b = mod-b;
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){return pw(k,mod-2);}

ll C(ll a,ll b){
	if(b>a)return 0;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(int i = 1;i<=n-1;i++){
		ll c = n-i+1;
		c -= 2;
		ll ans = 0;
		ans += c*10*9*9%mod*pw(10,n-i-2)%mod;
		if(ans>=mod)ans -= mod;
		ans += 10LL*9*pw(10,n-i-1)*2%mod;
		if(ans>=mod)ans -= mod;
		cout<<ans<<' ';
	}
	cout<<"10";
	return 0;
}
