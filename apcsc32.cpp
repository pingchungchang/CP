#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mod = 1e9+7;
int main(){
	io
	int n,m,q;
	cin>>n>>m>>q;
	ll dp[n+1][m+1];
	memset(dp,0LL,sizeof(dp));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>dp[i][j];
			dp[i][j] = -dp[i][j];
		}
	}
	dp[0][1] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(dp[i][j] == -1)dp[i][j] = 0;
			else{
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
				if(dp[i][j]>=mod)dp[i][j] -= mod;
			}
		}
	}
	while(q--){
		int r,c;
		cin>>r>>c;
		cout<<dp[r+1][c+1]<<'\n';
	}
	return 0;
}

