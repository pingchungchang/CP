#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll h,w;
	cin>>h>>w;
	ll ans = 0;

	int k;
	cin>>k;
	ll big = 0,small = 1e9;
	while(k--){
		ll x;
		cin>>x;
		big = max(big,x);
		small = min(small,x);
	}
	ans = max(ans,(big-small)*w);

	cin>>k;
	big = 0,small = 1e9;
	while(k--){
		ll x;
		cin>>x;
		big = max(big,x);
		small = min(small,x);
	}
	ans = max(ans,(big-small)*w);
 
	cin>>k;
	big = 0,small = 1e9;
	while(k--){
		ll x;
		cin>>x;
		big = max(big,x);
		small = min(small,x);
	}
	ans = max(ans,(big-small)*h);

	cin>>k;
	big = 0,small = 1e9;
	while(k--){
		ll x;
		cin>>x;
		big = max(big,x);
		small = min(small,x);
	}
	ans = max(ans,(big-small)*h);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
