#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n;
	cin>>n;
	map<ll,ll> m;
	for(ll i =0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		if(m.count(a) == 0){
			m[a] = 1;
		}
		else m[a]++;
		if(m.count(b+1) == 0){
			m[b+1] = -1;
		}
		else m[b+1]--;
	}
	ll now = 0;
	ll ans = 0;
	for(auto it = m.begin();it != m.end();it++){
		now += it->second;
		ans = max(ans,now);
	}
	cout<<ans;
}
