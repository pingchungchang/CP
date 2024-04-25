#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	ll mx = 0;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		mx = max(mx,v[i]);
	}
	ll sum = 0;
	ll ans = mx;
	sort(v.begin(),v.end());
	for(int i = 1;i<n;i++){
		ans -= v[i]*i-sum;
		sum += v[i];
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

