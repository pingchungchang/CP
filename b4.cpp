#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e6+10;
const ll mod = 1e9+7;
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
ll inv(ll k){return pw(k,mod-2);}

ll C(ll a,ll b){
	if(b>a)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

void solve(){
	ll a,b;
	cin>>a>>b;
	if(b<a*2-1){
		cout<<"0\n";
		return;
	}
	cout<<fac[a]*C(b-a*2+1+a,a)%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	int t;cin>>t;
	while(t--)solve();
}
