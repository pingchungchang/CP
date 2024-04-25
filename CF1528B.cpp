#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3")
const ll mod = 998244353 ;
const ll mxn = 2e6+10;
ll dp[mxn][15];
ll p[mxn];
bool isprime[mxn];
int main(){
	io
	ll n = 1e6;
	cin>>n;
	for(ll i =2;i<=n*2;i++){
		if(!isprime[i]){
			for(ll j = i;j<=n*2;j+=i){
				isprime[j] = true;
				dp[j][p[j]++] = i;
			}
		}
	}
//	return 0;
//	for(auto i:dp[100])cout<<i<<',';cout<<endl;
	ll ans = 1;
	ll pref = 1;
//	ll big = 0;
//	return 0;
	for(ll i = 2;i<=n;i++){
		ll total = 1LL;
		ll tmp = i;
		for(int kk = 0;kk<p[i*2];kk++){
			ll j = dp[i*2][kk];
			ll k = 1,pw = 1;
			while(tmp%j == 0){
				k += pw;
				tmp /=j;
				pw *= pw;
				pw %= mod;
				if(k>mod)k -= mod;
			}
			total = total*k%mod;
		}
		ans = pref+total;
		if(ans>mod)ans %= mod;
//		cout<<i*2<<' '<<total<<endl;
		pref += ans;
		if(pref>mod)pref %= mod;
	}
	cout<<ans;
}

