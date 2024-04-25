#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	vector<vector<ll>> dp(a+1,vector<ll>(b+1,INT_MAX));
	for(ll i =0;i<=a;i++){
		dp[i][i] =0;
	}
	for(ll i =0;i<=a;i++){
		dp[i][1] = i-1;
	}
	for(ll i =0;i<=b;i++){
		dp[1][i]= i-1;
	}
	dp[0][1] =0;
	dp[1][0] =0;
	for(ll i =2;i<=a;i++){
		for(ll j =2;j<=b;j++){
			for(ll k =1;k<i;k++){
				dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
			}
			for(ll k =1;k<j;k++)dp[i][j] = min(dp[i][j-k]+dp[i][k]+1,dp[i][j]);
		}
	}
//	for(ll i =1;i<=a;i++){
//		for(ll j =1;j<=b;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[a][b];
}
