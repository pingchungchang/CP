#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	io
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	vector<ll> pref(n+1,0);
	for(ll i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		pref[i]^= v[i-1];
	}
	for(ll i = 0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<(pref[b]^pref[a-1])<<'\n';
	}
}

