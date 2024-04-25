#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> dp;
vector<ll> v;

void rec(ll t,ll pos,ll state){
	ll one = 1;
	ll nxt = 0;
	while(one<dp[0].size()){
		ll x = state^one;
		if(x>state){
			ll k = state^one;
			ll dist = abs(nxt-pos);
			ll atime = dist+t;
			if(atime%v[nxt] != 0){
				atime = (atime/v[nxt]+1)*v[nxt];
			}
			if(atime<dp[nxt][k]){
				dp[nxt][k] = atime;
				rec(atime,nxt,k);
			}			
		}
		one<<=1;
		nxt++;
	}
	return;
}
int main(){
	ll n;
	cin>>n;
	v = vector<ll>(n+1,0);
	for(ll i =0;i<n;i++){
		cin>>v[i+1];
	}	
	dp = vector<vector<ll>>(n+1,vector<ll>(1<<(n+1),LONG_LONG_MAX));
	dp[0][1] = 0;
//	cout<<dp.size()<<' '<<dp[0].size();
	rec(0,0,1);
	ll ans =LONG_LONG_MAX;
	for(ll i =0;i<dp.size();i++){
		ans = min(ans,dp[i][dp[0].size()-1]);
	}
	cout<<ans;
}
