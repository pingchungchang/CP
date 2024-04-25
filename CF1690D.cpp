#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n,0LL);
	for(ll i= 0;i<n;i++){
		char c;
		cin>>c;
		if(c == 'B')v[i] = 1;
	}
	for(ll i = 1;i<n;i++)v[i] += v[i-1];
	ll ans= k-v[k-1];
	for(ll i = k;i<n;i++){
		ans = min(ans,k-(v[i]-v[i-k]));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

