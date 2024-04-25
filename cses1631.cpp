#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	ll total = 0;
	for(ll i =0;i<n;i++){
		cin>>v[i];
		total += v[i];
	}
	sort(v.begin(),v.end());
	total -= v[n-1];
	if(total >v[n-1])cout<<total+v[n-1];
	else cout<<2*v[n-1];
}
