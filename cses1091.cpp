#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	multiset<ll> s;
	ll n,m;
	cin>>n>>m;
	for(ll i =0;i<n;i++){
		ll k;
		cin>>k;
		s.insert(k);
	}
	for(ll i =0;i<m;i++){
		ll x;
		cin>>x;
		auto it = s.upper_bound(x);
		if(it == s.begin())cout<<"-1";
		else{
			cout<<*(--it)<<' ';
			s.erase(it);
		}
		if(i != m-1)cout<<'\n';
	}
}
