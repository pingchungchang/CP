#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;

ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

void solve(){
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i = 1;i*i<=n;i++){
		ll dif = n/i;
		if(dif>=i)dif--;
		ans = mad(ans,3LL*max(0LL,dif)+1);
		//cout<<i<<":"<<ans<<endl;
	}
	for(ll i = 2;i*i<=n;i++){
		ll big = n/i;
		if(big<=i)continue;
		ans = mad(ans,(big-i)*(i-1)%mod*6%mod);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
