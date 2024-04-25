#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
const ll inv2 = pw(2,mod-2);
int main(){
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i = 1;i*i<=n;i++){
		ans += i*(n/i-i+1);
		ans %= mod;
		if(n/i>i){
			ans += (n/i+i+1)%mod*((n/i-i)%mod)%mod*inv2%mod;
			ans %= mod;
		}
		// cout<<i<<":"<<ans<<endl;
	}
	cout<<ans;
}