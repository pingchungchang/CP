#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll ans = 0;
	ll l,f;
	cin>>l>>f;
	for(int i = 0;i<n;i++){	
		ll n = v[i];
		ans += f*((v[i]-l+l+f-1)/(l+f));
	}
	cout<<ans;
}
