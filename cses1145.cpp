#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> ans = {-1};
	for(ll i =0;i<n;i++){
		ll k;
		cin>>k;
		ll pos = lower_bound(ans.begin(),ans.end(),k)-ans.begin();
		if(pos>=ans.size())ans.push_back(k);
		else ans[pos] = k;
	}
	cout<<ans.size()-1;
}
