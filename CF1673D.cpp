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

const ll mod = 1e9+7;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	ll b0,db,nb,c0,dc,nc;
	cin>>b0>>db>>nb>>c0>>dc>>nc;
	if(b0>c0||c0+dc*(nc-1)>b0+db*(nb-1)||dc%db != 0||abs(b0-c0)%db != 0){
		cout<<0<<'\n';
		return;
	}
	if(b0>c0-dc||b0+db*(nb-1)<c0+dc*nc){
		cout<<-1<<'\n';
		return;
	}
	ll ans = 0LL;
	for(ll i = 1;i*i<=dc;i++){
		if(dc%i != 0)continue;
		ll now = i;
		if(now*db/gcd(now,db) == dc){
			ans += (dc/now)*(dc/now)%mod;
			ans %= mod;
		}
		now = dc/i;
		if(now == i)continue;
		if(now*db/gcd(now,db) == dc){
			ans += (dc/now)*(dc/now)%mod;
			ans %= mod;
		}
	}
	cout<<ans%mod<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

