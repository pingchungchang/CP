#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll mid = v[n/2];
	ll ans =0;
	for(ll i =0;i<n;i++){
		ans += abs(v[i]-mid);
	}
	cout<<ans;
}
