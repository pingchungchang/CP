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
	ll n,m;
	cin>>n>>m;
	map<ll,ll> mp;
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		ll k = 0LL;
		for(ll j = 0;j<m;j++){
			ll now;
			cin>>now;
			if((now&1) != 0)k += (1<<j);
		}
		ans += mp[k];
		mp[k]++;
	}
	cout<<ans;
}

