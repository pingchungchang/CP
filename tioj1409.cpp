#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
void solve(){
	ll sum = 0;
	ll l = 0;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		sum += k;
		l = max(l,k);
	}
	if(l*2<sum)cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	while(cin>>n){
		solve();
	}
}
