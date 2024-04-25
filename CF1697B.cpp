#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n+1,0);
	for(ll i = 1;i<=n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	vector<ll> pref(n+1,0);
	for(ll i = 1;i<=n;i++)pref[i] = pref[i-1]+v[i];
	for(ll i = 0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<pref[n-(a-b)]-pref[n-a]<<'\n';
	}
	return;
}
int main(){
	io
	solve();
}

