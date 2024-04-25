#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dp(123,make_pair(0,0));
int main(){
	dp[1] = make_pair(1,3);
	dp[2] = make_pair(4,12);
	for(int i = 3;i<=120;i++){
		dp[i].first = dp[i-1].first+dp[i-1].second;
		dp[i].second = 4*dp[i-1].second;
	}
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans += dp[i].first;
	}
	cout<<ans;
}
