#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll total = 0;
	map<ll,ll> mp;
	while(n--){
		ll a,b;
		cin>>a>>b;
		total += b;
		mp[a+1] += b;
	}
	if(total<k){
		cout<<1;
		return 0;
	}
	for(auto &i:mp){
		total -= i.sc;
		if(total<k){
			cout<<i.fs;
			return 0;
		}
	}
	assert(false);
	return 0;
}
