#include <bits/stdc++.h>
using namespace std;

#define int long long
int dp[755];
signed main(){
	memset(dp,0LL,sizeof(dp));
	dp[0] = 1;
	for(int i = 1;i<=750;i+=2){
		for(int j = i;j<=750;j++){
			dp[j] += dp[j-i];
		}
	}
	int t;
	cin>>t;
	for(int  i = 0;i<t;i++){
		int k;
		cin>>k;
		cout<<dp[k]<<'\n';
	}
	return 0;
}
