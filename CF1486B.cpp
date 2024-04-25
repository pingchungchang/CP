#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin>>n;
	vector<ll> x(n);
	vector<ll> y(n);
	for(ll i = 0;i<n;i++)cin>>x[i]>>y[i];
	if((n&1)){
		cout<<1<<'\n';
		return;
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ll ans = (x[n/2]-x[n/2-1]+1)*(1+y[n/2]-y[n/2-1]);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
