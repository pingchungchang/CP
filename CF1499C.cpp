#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<vector<ll>> pref(n,vector<ll>(2,0));
	pref[0][0] = v[0];
	for(int i = 1;i<n;i++){
		pref[i] = pref[i-1];
		pref[i][i&1]+= v[i];
	}
	ll ans = LONG_LONG_MAX;
	vector<ll> smallest = {v[0],v[1]};
	for(int i = 1;i<n;i++){
		ll tmp = pref[i][0]+pref[i][1];
		smallest[i%2] = min(smallest[i%2],v[i]);
		tmp += smallest[0]*(n-(i+2)/2)+smallest[1]*(n-(i+1)/2);
		ans = min(ans,tmp);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
