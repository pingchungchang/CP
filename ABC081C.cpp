#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n,k;
	cin>>n>>k;
	map<ll,ll> mp;
	for(ll i = 0;i<n;i++){
		ll x;
		cin>>x;
		if(mp.count(x) == 0)mp[x] = 1;
		else mp[x]++;
	}
	vector<ll> v;
	for(auto it:mp){
		v.push_back(it.second);
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	n = v.size();
	for(ll i = 0;i<n-k;i++)ans += v[i];
	cout<<ans;
}

