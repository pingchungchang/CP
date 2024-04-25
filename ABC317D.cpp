#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e18;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	vector<pll> v;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		sum += c;
		if(a>b)v.push_back({0,c});
		else v.push_back({(b-a+1)>>1,c});
	}
	ll dp[sum+1];
	fill(dp,dp+sum+1,inf);
	dp[0] = 0;
	for(auto &i:v){
		for(int j = sum;j>=i.sc;j--){
			dp[j] = min(dp[j],dp[j-i.sc]+i.fs);
		}
	}
	ll ans = inf;
	for(int j = sum/2+1;j<=sum;j++)ans = min(ans,dp[j]);
	cout<<ans;
}
