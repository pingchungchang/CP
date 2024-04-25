#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> v(n);
	for(ll i =0;i<n;i++)cin>>v[i];
	vector<pair<ll,ll>> dp(1<<n,make_pair(n+1,0));
	dp[0] = make_pair(0,x);
	for(ll i =1;i<(1<<n);i++){
		for(ll j =0;j<=n;j++){
			if((i&(1<<j)) != 0){
				ll prev = i^(1<<j);
				if(dp[prev].second+v[j]<=x){
					pair<ll,ll> temp = make_pair(dp[prev].first,dp[prev].second+v[j]);
					dp[i] = min(dp[i],temp);
				}
				else{
					pair<ll,ll> temp = make_pair(dp[prev].first+1,min(v[j],dp[prev].second));
					dp[i] = min(dp[i],temp);
				}
			}
		}
	}
//	for(ll i =0;i<dp.size();i++){
//		cout<<i<<' '<<dp[i].first<<' '<<dp[i].second<<endl;
//	}
	cout<<dp[(1<<n)-1].first;
}
