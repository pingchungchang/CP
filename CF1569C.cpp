#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mxn = 2e5+10;
ll fac[mxn];
const ll mod = 998244353;

ll pw(ll a,ll b){
	ll ans = 1;
	while(b != 0){
		if((b&1) != 0)ans = ans*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return ans;
}

ll inverse(ll a){
	return pw(a,mod-2);
}
ll C(ll a,ll b){
	if(b>a)return 0LL;
	return fac[a]*inverse(fac[b])%mod*inverse(fac[a-b])%mod;
}
void solve(){
	int n;
	cin>>n;
	map<ll,ll> mp;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		mp[k]++;
	}
	if(mp.rbegin()->sc >1){
		cout<<fac[n]<<'\n';
		return;
	}
	if(mp.size() == 1){
		cout<<"1\n";
		return;
	}
	if((++mp.rbegin())->fs != mp.rbegin()->fs-1){
		cout<<"0\n";
		return;
	}
	ll ans = 0;
	ll sec = (++mp.rbegin())->sc;
	for(ll i = 1;i<=n;i++){
		ans += C(n-i,sec)*fac[sec]%mod*fac[n-1-sec]%mod;
		ans %= mod;
	}
	ans = (fac[n]+mod-ans)%mod;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	fac[0] = 1;
	for(ll i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
//	for(int i = 0;i<10;i++)cout<<fac[i]<<' ';
//	cout<<C(4,2)<<endl;
	int t;
	cin>>t;
	while(t--)solve();
}

