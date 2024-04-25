#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	long long ans =INT_MIN;
	for(ll i =0;i<n;i++){
		cin>>v[i];
		if(i !=0){
			v[i] = max(v[i],v[i-1]+v[i]);
		}
		ans = max(ans,v[i]);
	}
	cout<<ans;
}
