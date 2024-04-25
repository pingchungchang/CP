#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
vector<ll> dp(2*1e5+5,0);
ll len(ll n){
	ll returns =0;
	while(n != 0){
		n>>=1;
		returns++;
	}
	return returns;
}
int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i = 1;i<=k;i++)dp[i] = 1;
	for(ll i = k;i>1;i--){
		dp[i-2] =(dp[i-2] + dp[i])%mod;
		dp[i-1] = (dp[i-1]+dp[i])%mod;
	}
	set<ll> st;
	for(ll i = 0;i<n;i++){
		ll x;
		cin>>x;
		st.insert(x);
	}
	vector<ll> used;
	for(auto it = st.begin();it != st.end();it++){
		ll now = *it;
		while(now != 0){
			if(now%4 == 0)now>>=2;
			else if(now%2 == 1)now>>=1;
			else break;
			if(st.find(now) != st.end())used.push_back(*it);
		}
	}
	for(ll i:used)st.erase(i);
	ll ans = 0;
	for(auto i:st){
//		cout<<i<<' ';
//		cout<<len(i)<<' ';
		ans += dp[len(i)];
		ans %= mod;
	}
	cout<<ans;
}
