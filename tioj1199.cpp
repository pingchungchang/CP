#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll n,x,mod;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

void solve(){
	ll ans = 0;
	for(ll i = 0;i<mod;i++){
		if(i == 0&&n == 0)continue;
		if(pw(i,n) == x)ans++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>x>>n>>mod){
		if(!x&&!n&&!mod)return 0;
		solve();
	}
}
