#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main(){
	vector<pair<ll,ll>> dp(31,make_pair(0,0));
	dp[1] = make_pair(2,3);
	for(int i = 2;i<30;i++){
		dp[i] = make_pair(dp[i-1].first+dp[i-1].second*2,dp[i-1].first+dp[i-1].second*3);
	}
	dp[0] = make_pair(0,1);
	while(cin>>n){
		if(n==-1)return 0;
		if(n%2==0)cout<<dp[n/2].second<<'\n';
		else cout<<0<<'\n';
	}
}
