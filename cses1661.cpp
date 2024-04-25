#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll,ll> m;
int main(){
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n+1);
	v[0] = 0;
	for(ll i =1;i<=n;i++){
		cin>>v[i];
		v[i]+= v[i-1];
	}
	ll ans = 0;
	for(ll i =0;i<=n;i++){
		ll tar =  v[i]-k;
		if(m.count(tar) != 0)ans += m[tar];
		if(m.count(v[i]) == 0)m[v[i]] = 1;
		else m[v[i]]++;
	}
	cout<<ans;
}
