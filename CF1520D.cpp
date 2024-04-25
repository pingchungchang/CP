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
	vector<int> v(n);
	map<int,ll> mp;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		mp[v[i]-i]++;
	}
	ll ans = 0;
	for(auto i:mp){
		ans += i.sc*(i.sc-1)/2;
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

