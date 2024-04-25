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
	for(auto &i:v)cin>>i;
	ll ans =0;
	ll x = v[0];
	for(ll i = 1;i<n;i++){
		ans += abs(v[i]-v[i-1]);
		if(v[i]<v[i-1])x += v[i]-v[i-1];
	}
	ans += abs(x);
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

