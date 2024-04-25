#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3030;
int mod;
int dp[2][mxn][2];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n>>mod;
	bool roll = 0;
	memset(dp,0,sizeof(dp));
	dp[roll][1][0] = 1;
	dp[roll][0][1] = 1;
	for(int i = 2;i<=n;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 0;j<mxn;j++){
			if(j>=1)dp[roll][j][0] = mad(dp[roll][j][0],dp[roll^1][j-1][0]);
			if(j>=2)dp[roll][j][0] = mad(dp[roll][j][0],mad(dp[roll^1][j-2][1],dp[roll^1][j-2][1]));
			dp[roll][j][1] = mad(dp[roll^1][j][0],dp[roll^1][j][1]);
			if(j>=1)dp[roll][j][1] = mad(dp[roll][j][1],1ll*dp[roll^1][j-1][1]*3%mod);
		}
	}
	for(int i = 1;i<n;i++)cout<<dp[roll][i][1]<<' ';
	return 0;
}
