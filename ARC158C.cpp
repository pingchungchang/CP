#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll calc(ll k){
	ll re = 0;
	while(k)re += k%10,k/=10;
	return re;
}

void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	ll ans = 0;
	for(auto &i:arr){
		cin>>i;
		ans += calc(i)*(n*2);
	}
	ll now = 10;
	while(now<1e18){
		vector<ll> v;
		for(auto &i:arr)v.push_back(i%now);
		sort(v.begin(),v.end());
		auto v2 = v;
		reverse(v2.begin(),v2.end());
		ll p = 0;
		for(auto &i:v){
			while(p<v.size()&&v2[p]+i>=now)p++;
			ans -= 9*p;
		}
		now *= 10;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
