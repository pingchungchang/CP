#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> v;
	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	ll time = 0;
	ll ans =0;
	for(ll i =0;i<n;i++){
		time += v[i].first;
		ans += v[i].second-time;
	}
	cout<<ans;
}
