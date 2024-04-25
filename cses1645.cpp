#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i =0;i<n;i++)cin>>v[i];
	stack<pair<ll,ll>> s;
	for(ll i =0;i<n;i++){
		ll k = v[i];
		while(!s.empty()&&s.top().first>=v[i]){
			s.pop();
		}
		if(s.empty()){
			v[i] =0;
		}
		else{
			v[i] = s.top().second+1;
		}
		s.push(make_pair(k,i));
	}
	for(ll i =0;i<n;i++){
		cout<<v[i];
		if(i != n-1)cout<<' ';
	}
}
