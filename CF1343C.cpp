#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pll dp[2][2];
	bool roll = 0;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	dp[roll][0] = dp[roll][1] = {0,0};
	for(auto &i:arr){
		roll ^= 1;
		dp[roll][0] = dp[roll^1][0];
		dp[roll][1] = dp[roll^1][1];
		if(i>0){
			dp[roll][0] = max(dp[roll][0],make_pair(dp[roll^1][1].fs+1,dp[roll^1][1].sc+i));
		}
		else{
			dp[roll][1] = max(dp[roll][1],make_pair(dp[roll^1][0].fs+1,dp[roll^1][0].sc+i));
		}
	}
	cout<<max(dp[roll][0],dp[roll][1]).sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
