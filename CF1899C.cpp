#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll dp[2];
	dp[0] = dp[1] = 0;
	int n;
	cin>>n;
	ll ans = -1e18;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		ans = max(ans,arr[i]);
		ll tmp[2] = {0ll,0ll};
		if(abs(arr[i])&1)tmp[1] = max(tmp[1],dp[0]+arr[i]),ans = max(ans,dp[0]+arr[i]);
		else tmp[0] = max(tmp[0],dp[1]+arr[i]),ans = max(ans,dp[1]+arr[i]);
		dp[0] = tmp[0];
		dp[1] = tmp[1];
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
