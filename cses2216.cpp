#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	for(ll i =0;i<n;i++){
		ll k;
		cin>>k;
		v[i] = make_pair(k,i);
	}
	sort(v.begin(),v.end());
	ll ans = n;
	for(ll i =1;i<n;i++){
		if(v[i].second>v[i-1].second){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
