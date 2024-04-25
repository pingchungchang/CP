#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int main(){
	io
	ll ans = LONG_LONG_MAX;
	ll dp = 0;
	ll n,l,r;
	cin>>n>>l>>r;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(ll i = 0;i<n;i++){
		ans = min(ans,dp+r*(n-i));
		dp += v[i];
		dp = min(dp,l*(i+1));
//		cout<<i<<' '<<dp<<'\n';
	}
	ans = min(ans,dp);
	cout<<min({ans,l*n,r*n});
}

