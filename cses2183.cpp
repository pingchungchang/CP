#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(ll i=1;i<n;i++)v[i] += v[i-1];
	
	if(v[0] != 1){
		cout<<1;
		return 0;
	}
	for(ll i =1;i<n;i++){
		if(v[i-1]+1<v[i]-v[i-1]){
			cout<<v[i-1]+1;
			return 0;
		}
	}
	cout<<v[n-1]+1;
	return 0;
}
