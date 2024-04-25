#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	for(ll i =0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v[i] = make_pair(b,a);
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	ll back = INT_MIN;
	for(ll i =0;i<n;i++){
		if(v[i].second>=back){
			back = v[i].first;
			ans++;
		}
	}
	cout<<ans;
	
}
