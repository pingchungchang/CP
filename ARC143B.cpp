#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn= 505*505;
const ll mod = 998244353;
ll fac[mxn];

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv(ll k){return pw(k,mod-2);}

ll C(ll a,ll b){
	return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}

void solve(){
	ll n;
	cin>>n;
	ll total = fac[n*n];
	for(int i = 0;i<n*n;i++){
		ll tmp = C(n*n,n*2-1);
		tmp = tmp*fac[n-1]%mod*fac[n-1]%mod*fac[(n-1)*(n-1)]%mod;
		total = total+mod-tmp;
		if(total>=mod)total -= mod;
	}
	cout<<total;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = fac[1] = 1;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	int t = 1;
	while(t--)solve();
}
