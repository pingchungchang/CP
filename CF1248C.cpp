#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;
const ll mxn = 1e5+10;

ll fac[mxn],ifac[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;;
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
	if(a<b)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
		ifac[i] = inv(fac[i]);
	}
	ll n,m;
	cin>>n>>m;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ll d = n-i;
		if(d>i)continue;
		//cout<<n<<' '<<i<<' '<<d<<endl;
		ans = mad(ans,C(i,d)*2%mod);
	}
	for(int i = 1;i<m;i++){
		ll d = m-i;
		if(d>i)continue;
		//cout<<m<<' '<<i<<' '<<d<<endl;
		ans = mad(ans,C(i,d)*2%mod);
	}
	cout<<ans;
}
