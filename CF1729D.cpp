#include <bits/stdc++.h>
using namespace std;


#define ll long long
void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr){
		cin>>i;
		i = -i;
	}
	multiset<ll> neg,pos;
	for(auto &i:arr){
		ll k;
		cin>>k;
		i += k;
		if(i>=0)pos.insert(i);
		else neg.insert(-i);
	}
	ll ans = 0;
	ll cnt = pos.size();
	for(auto it = pos.rbegin();it != pos.rend();it++){
		if(neg.empty())break;
		ll v = *it;
		auto p = neg.upper_bound(v);
		if(p == neg.begin())continue;
		neg.erase(--p);
		ans++;
		cnt--;
	}
	// cout<<ans<<' '<<cnt<<":";
	cout<<ans+cnt/2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}