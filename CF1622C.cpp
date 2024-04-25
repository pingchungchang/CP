#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int n;
	ll k;
	cin>>n>>k;
	ll v[n];
	ll ans = LONG_LONG_MAX;
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(v,v+n);
	ll pref[n+1] = {};
	pref[0] = v[0];
	for(int i = 1;i<n;i++)pref[i] = pref[i-1]+v[i];
	for(int i = 0;i<n;i++){
		ll tmp = k-pref[n-i-1]+v[0];
		ll tt = tmp/(i+1);
		if(tmp<0&&tt*(i+1) != tmp)tt--;
		ans = min(ans,i+max(0LL,v[0]-tt));
	}
	ans = max(ans,(ll)0);
	cout<<ans<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
