#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;

ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

void solve(){
	int n,k;
	cin>>n>>k;
	ll dp[2][64];
	memset(dp,0LL,sizeof(dp));
	bool roll = false;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:arr){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 0;j<64;j++){
			dp[roll][j&i] = mad(dp[roll][j&i],dp[roll^1][j]);
		}
		for(int j = 0;j<64;j++)dp[roll][j] = mad(dp[roll][j],dp[roll^1][j]);
		dp[roll][i] = mad(dp[roll][i],1);
	}
	ll ans = 0;
	for(int i = 0;i<64;i++){
		if(__builtin_popcount(i) == k)ans = mad(ans,dp[roll][i]);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
