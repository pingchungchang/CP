#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	set<ll> road;
	road.insert(0);
	road.insert(n);
	multiset<ll> s;
	s.insert(n);
	for(ll i =0;i<m;i++){
		ll k;
		cin>>k;
		auto it1 = road.lower_bound(k);
		if(*it1==k){
			cout<<*s.rbegin()<<' ';
			continue;
		}
		auto it2 = it1;
		--it2;
		s.erase(s.find(*it1-*it2));
		s.insert(k-*it2);
		s.insert(*it1-k);
		road.insert(k);
		cout<<*s.rbegin()<<' ';
	}
}
