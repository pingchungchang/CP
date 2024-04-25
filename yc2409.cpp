#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 6e5+10;
const ll mod = 998244353;
ll fac[mxn],ifac[mxn];

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}

ll C(ll a,ll b){
	if(a>=mxn||b>=mxn)return -1;
	if(a<b)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll x,y,z,w;
	cin>>x>>y>>z>>w;
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
		ifac[i] = inv(fac[i]);
	}
	if(!w)cout<<C(x,z)*fac[x-z]%mod*C(y,w)%mod*fac[y-w]%mod*C(x+y-z-w-1,x-z)%mod;
	else cout<<C(x,z)*fac[x-z]%mod*C(y,w)%mod*fac[y-w]%mod*C(x+y-z-w-1,y-w)%mod;
}
