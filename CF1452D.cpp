#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 4e5+10;
const ll mod = 998244353;
ll fac[mxn],ifac[mxn];
inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;a = a*a%mod;
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
inline ll mub(ll a,ll b){
	if(!b)return a;
	return mad(a,mod-b);
}

inline ll C(ll a,ll b){
	if(b>a)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(ll i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	ll n;
	cin>>n;
	ll cnt = 0;
	for(ll i = 1;i<=n;i++){
		ll dt = n-i;
		if(dt&1)continue;
		dt>>=1;
		cnt = mad(cnt,C(i+dt-1,i-1));
	}
	cout<<cnt*inv(pw(2,n))%mod;
	return 0;
}
