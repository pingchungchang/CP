#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
int dp[mxn][mxn];

int calc(int n,int m){
	if(!n||!m)return dp[n][m] = 0;
	if(dp[n][m] != -1)return dp[n][m];
	if(n == m)return 1;
	dp[n][m] = n*m;
	for(int i = 1;i<=min(n,m);i++){
		dp[n][m] = min(dp[n][m],1+calc(i,m-i)+calc(n-i,m));
		dp[n][m] = min(dp[n][m],1+calc(n-i,i)+calc(n,m-i));
		dp[n][m] = min(dp[n][m],1+calc(n-i,m-i)+calc(n-i,i)+calc(i,m-i));
	}
	return dp[n][m];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	cout<<calc(n,m);
}
