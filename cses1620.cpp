#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
vector<ll> v;
ll t,n;
bool f(ll x){
	ll total = 0;
	for(ll i =0;i<n;i++)total += x/v[i];
	if(total>=t)return true;
	else return false;
	
}

int main(){
	cin>>n>>t;
	v =vector<ll>(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
	}
	ll l = 0;
	ll r = LONG_LONG_MAX;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid) == true){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout<<l;
	return 0;
}
