#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll now = 0;
	vector<ll> v = {0LL};
	ll n;
	cin>>n;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		now += k;
		now %= 360;
		v.push_back(now);
	}
	sort(v.begin(),v.end());
	v.push_back(*v.begin()+360);
	ll ans = 0;
	for(ll i = 1;i<v.size();i++){
		ans = max(ans,v[i]-v[i-1]);
	}
	cout<<ans;
}

