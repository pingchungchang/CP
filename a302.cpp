#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e6+10;
const ll mod = 1e4+7;
ll fac[mxn],ifac[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){return pw(k,mod-2);}

inline ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	ll a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	cout<<pw(a,n)*pw(b,m)%mod*C(k,n)%mod;

}
