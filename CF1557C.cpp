#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
ll pw(ll a,ll b){
	ll re = 1;
	while(b != 0){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}

ll inverse(ll a){
	return pw(a,mod-2);
}
const ll mxn = 2e5+10;
ll fac[mxn];
ll C(ll a,ll b){
	if(b>a)return 0LL;
	return fac[a]*inverse(fac[b])%mod*inverse(fac[a-b]);
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans = 0LL;
	ll dp = 1;
	for(ll i = k;i>0;i--){
		if(n&1){
			dp = dp*(pw(2,n-1)+1)%mod;
		}
		else{
			ans = (ans+dp*pw(2,n*(i-1))%mod)%mod;
			dp = dp*(pw(2,n-1)+mod-1)%mod;
		}
	}
//	cout<<ans<<' '<<dp<<'\n';
	cout<<(ans+dp)%mod<<'\n';
}
int main(){
	io
	fac[0] =1;
	for(ll i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
	}
	ll t;
	cin>>t;
	while(t--)solve();
}
/*
5
200000 200000
24567 23423
1 200000
200000 1
200000 0

226490044
470587519
175895282
87947641
1
*/

