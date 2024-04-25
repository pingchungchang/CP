#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 998244853;


int main(){
	ll n,k;
	cin>>n>>k;
	ll now = 0;
	ll pre = 1;
	vector<ll> v = {0};
	map<ll,ll> mp;
	for(ll i = 1;i<=n;i++){
		ll tmp;
		cin>>tmp;
		mp[tmp]++;
	}
	for(auto i:mp){
		v.push_back(i.sc);
	}
	n = v.size();
	vector<vector<ll>> dp(k+1,vector<ll>(n+1,0LL));
	for(ll i = 0;i<=n;i++){
		dp[0][i] = 1;
	}
	for(ll i = 1;i<=k;i++){
		for(ll j = 1;j<n;j++){
			dp[i][j] = (dp[i][j-1]+dp[i-1][j-1]*v[j]%mod)%mod;
		}
	}
	//	for(int i = 0;i<=k;i++){
	//		for(int j = 1;j<n;j++){
	//			cout<<dp[i][j]<<' ';
	//		}
	//		cout<<endl;
	//	}
	cout<<dp[k][n-1];
}

