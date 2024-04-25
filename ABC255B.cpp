#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	io
	ll n,k;
	cin>>n>>k;
	ll ans = 0LL;
	vector<pll> v(n);
	vector<ll> p(k);
	for(ll i = 0;i<k;i++){
		cin>>p[i];
		p[i]--;
	}
	for(ll i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
	}
	for(ll i = 0;i<n;i++){
		ll dist = LONG_LONG_MAX;
		for(ll j = 0;j<k;j++){
			ll now = p[j];
			dist = min(dist,(v[now].fs-v[i].fs)*(v[now].fs-v[i].fs)+(v[now].sc-v[i].sc)*(v[now].sc-v[i].sc));
		}
		ans = max(ans,dist);
	}
	cout<<fixed<<setprecision(10)<<(double)sqrt(ans);
}

