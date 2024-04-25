#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n){
//	vector<ll> v(n+1,0);
//	for(ll i = 1;i<=n;i++){
//		v[n/i]++;
//	}
//	for(ll i = n;i>=1;i--)cout<<i<<':'<<v[i]<<'\n';
	ll ans = 0;
	ll now = 1;
	while(n/now>=now){
		ans += now*(n/now-n/(now+1));
		if(now != n/now){
			ll n2 = n/now;
			ans += n2*(n/n2-n/(n2+1));
		}
		now++;
	}
	cout<<ans<<'\n';
}
int main(){
	ll n;
	while(cin>>n){
		if(n==0)return 0;
		solve(n);
	}
}

//i:n/i-n/(i+1);
