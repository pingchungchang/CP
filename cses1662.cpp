#include <bits/stdc++.h>
using namespace std;

#define ll long longn
map<ll,ll> mp;
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n+1);
	v[0] = 0;
	for(ll i =1;i<=n;i++){
		cin>>v[i];
		v[i] -= (v[i]/n)*n;
		if(v[i]<0)v[i]+=n;
		v[i] += v[i-1];
		v[i] = v[i]%n;
	}
	ll ans =0;
	for(ll i =0;i<=n;i++){
		ll tar = v[i]-n;
		if(tar<0)tar += n;
		if(mp.count(tar) != 0)ans += mp[tar];
		if(mp.count(v[i]) == 0)mp[v[i]] = 1;
		else mp[v[i]]++;
	}
	cout<<ans;
}
