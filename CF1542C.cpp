#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
ll lpf(ll k){
	for(ll i = 2;i<=k;i++){
		if(k%i == 0)return i;
	}
	return -1;
}
const ll mod = 1e9+7;
void solve(){
	ll n;
	cin>>n;
	ll lcm = 1LL;
	ll ans = 0;
	for(ll i = 2;i<=100;i++){
		if(lcm>n)break;
//		cout<<(n/lcm/lpf(i)*(lpf(i)-1)+(n/lcm)%lpf(i))<<'\n';
//		cout<<i<<' '<<lcm<<' '<<lpf(i)<<endl;
		if(lcm%i == 0)continue;
		ans += (n/lcm/lpf(i)*(lpf(i)-1)+(n/lcm)%lpf(i))%mod*i%mod;;
		ans %= mod;
		lcm = lcm*i/gcd(lcm,i);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
	
}

